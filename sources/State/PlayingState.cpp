#include <iostream>
#include <cmath>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "PlayingState.hpp"
#include "../Application.hpp"
#include "../Mesh/ChunkMeshBuilder.hpp"
#include "../Math/Ray.hpp"
#include "../Util/ChunkPos.hpp"
#include "../Util/Clock.hpp"

#include "../Registry/Blocks.hpp"

PlayingState::PlayingState(Application& app) :
    State(app),
    m_world(1, 1),
    m_player(m_world.getPlayer()),
    m_buttons(MouseButtonMappings::getInstance()),
    m_keys(KeyMappings::getInstance()),
    m_mouse(app.getMouse())
{
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_GL_SetSwapInterval(1);

    for (const auto& chunk : m_world.getChunks()) {
        for (const auto& section : chunk.second.getSections()) {
            m_chunkRenderer.add(section);
        }
    }
}

void PlayingState::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
            m_camera.setRatio((float)m_app.getWindow().getWidth() / m_app.getWindow().getHeight());
        }
    }
}

void PlayingState::handleInput() {
    keyboardInput();
    mouseInput();
}
Clock timer;
void PlayingState::mouseInput() {

    // redo
    auto dir = glm::vec3(
        std::cos(glm::radians(m_player.getYaw())) * std::cos(glm::radians(m_player.getPitch())),
        std::sin(glm::radians(m_player.getPitch())),
        std::sin(glm::radians(m_player.getYaw())) * std::cos(glm::radians(m_player.getPitch()))
    );


    glm::vec3 last;
    glm::vec3 ifBreak;
    bool canInteract = false;
    auto pos = glm::vec3(m_player.getPosition().x, m_player.getPosition().y + 1.6f, m_player.getPosition().z);
    for (Ray ray{pos, dir};
         glm::length(ray.end - ray.origin) <= 5;
         ray.step(0.05f))
    {
        int x = ray.end.x;
        int y = ray.end.y;
        int z = ray.end.z;

        const Block& block = m_world.getBlock({x, y, z});
        if (!block.isAir()) {
            canInteract = true;
            ifBreak = ray.end;
            break;
        }
        if (glm::length(ray.end - ray.origin) == 5 && block.isAir()) {
            canInteract = false;
        }
        last = ray.end;
    }

    if (m_buttons.BREAK.heldDown()) {
        int x = static_cast<int>(ifBreak.x);
        int y = static_cast<int>(ifBreak.y);
        int z = static_cast<int>(ifBreak.z);

        if (canInteract && timer.getElapsedTime().asSeconds() > 0.15) {
            m_world.setBlock(Blocks::getInstance().AIR, {x, y, z});
            m_chunkRenderer.add(m_world.getChunks().at(
                {int(std::floor(float(x) / CHUNK_SIZE)), int(std::floor(float(z) / CHUNK_SIZE))}
            ).getSections()[y / CHUNK_SIZE]);
            timer.restart();
        }
    }
    if (m_buttons.PUT.heldDown()) {
       
        int x = static_cast<int>(last.x);
        int y = static_cast<int>(last.y);
        int z = static_cast<int>(last.z);
        
        if (canInteract && timer.getElapsedTime().asSeconds() > 0.15) {
            m_world.setBlock(Blocks::getInstance().STONE, {x, y, z});
            m_chunkRenderer.add(m_world.getChunks().at(
                {int(std::floor(float(x) / CHUNK_SIZE)), int(std::floor(float(z) / CHUNK_SIZE))}
            ).getSections()[y / CHUNK_SIZE]);
            //std::cout << "Rebuild\n";
            timer.restart();
        }
    }

    m_player.setYaw(m_player.getYaw() + 0.15f * m_mouse.getDX());
    float a = m_player.getPitch() - 0.15f * m_mouse.getDY();
    if (a >= -89.f && a <= 89.f) {
        m_player.setPitch(a);
    } else if (a > 89.f) {
        m_player.setPitch(89.f);
    } else if (a < -89.f) {
        m_player.setPitch(-89.f);
    }
}

void PlayingState::keyboardInput() {

    glm::vec3 motion(0.f);
    if (m_keys.FORWARD.heldDown()) {
        motion.x += std::cos(glm::radians(m_player.getYaw()));
        motion.z += std::sin(glm::radians(m_player.getYaw()));
    }
    if (m_keys.BACKWARD.heldDown()) {
        motion.x -= std::cos(glm::radians(m_player.getYaw()));
        motion.z -= std::sin(glm::radians(m_player.getYaw()));
    }
    if (m_keys.LEFT.heldDown()) {
        motion.x -= std::cos(glm::radians(m_player.getYaw() + 90));
        motion.z -= std::sin(glm::radians(m_player.getYaw() + 90));
    }
    if (m_keys.RIGHT.heldDown()) {
        motion.x += std::cos(glm::radians(m_player.getYaw() + 90));
        motion.z += std::sin(glm::radians(m_player.getYaw() + 90));
    }
    if (m_keys.UP.heldDown()) {
        motion.y += 1;
    }
    if (m_keys.DOWN.heldDown()) {
        motion.y -= 1;
    }
    m_player.setMotion(motion);
}

void PlayingState::update(float dt) {

    m_world.update(dt);

    m_camera.setPosition(m_player.getPosition());
    m_camera.setDirection(
        glm::vec3(
            std::cos(glm::radians(m_player.getYaw())) * std::cos(glm::radians(m_player.getPitch())),
            std::sin(glm::radians(m_player.getPitch())),
            std::sin(glm::radians(m_player.getYaw())) * std::cos(glm::radians(m_player.getPitch()))
        )
    );
}

void PlayingState::render() {


 // glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glClearColor(139 / 255.f, 170 / 255.f, 252 / 255.f, 1.f);

    m_chunkRenderer.render(m_camera);
}
