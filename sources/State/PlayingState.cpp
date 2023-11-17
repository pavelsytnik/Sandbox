#include <iostream>
#include <cmath>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "PlayingState.hpp"
#include "../Application.hpp"
#include "../Mesh/ChunkMeshBuilder.hpp"

PlayingState::PlayingState(Application& app) :
    State(app),
    m_world(10, 10, 10),
    m_player(m_world.getPlayer()),
    m_buttons(MouseButtonMappings::getInstance()),
    m_keys(KeyMappings::getInstance()),
    m_mouse(app.getMouse())
{
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_GL_SetSwapInterval(1);

    ChunkMeshBuilder builder(m_world);
    builder.create();
    builder.build();
    m_chunkMesh = builder.getResult();
    m_chunkMesh->setVBO();

    m_chunkRenderer.add(m_chunkMesh);
}

void PlayingState::handleEvent(const SDL_Event& event) {
    State::handleEvent(event);
}

void PlayingState::handleInput() {
    keyboardInput();
    mouseInput();
}

void PlayingState::mouseInput() {
    if (m_buttons.BREAK->heldDown()) {
        std::cout << "BREAK\n";
    }

    m_player.setYaw(m_player.getYaw() + 0.15f * m_mouse.getDX());
    m_player.setPitch(m_player.getPitch() - 0.15f * m_mouse.getDY());
}

void PlayingState::keyboardInput() {

    glm::vec3 motion(0.f);
    if (m_keys.FORWARD->heldDown()) {
        motion.x += std::cos(glm::radians(m_player.getYaw()));
        motion.z += std::sin(glm::radians(m_player.getYaw()));
    }
    if (m_keys.BACKWARD->heldDown()) {
        motion.x -= std::cos(glm::radians(m_player.getYaw()));
        motion.z -= std::sin(glm::radians(m_player.getYaw()));
    }
    if (m_keys.LEFT->heldDown()) {
        motion.x -= std::cos(glm::radians(m_player.getYaw() + 90));
        motion.z -= std::sin(glm::radians(m_player.getYaw() + 90));
    }
    if (m_keys.RIGHT->heldDown()) {
        motion.x += std::cos(glm::radians(m_player.getYaw() + 90));
        motion.z += std::sin(glm::radians(m_player.getYaw() + 90));
    }
    if (m_keys.UP->heldDown()) {
        motion.y += 1;
    }
    if (m_keys.DOWN->heldDown()) {
        motion.y -= 1;
    }
    m_player.setMotion(motion);
}

void PlayingState::update(std::uint64_t dt) {

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

void PlayingState::resize() {
    int w, h;
    SDL_GetWindowSize(m_app.getContext().getWindow(), &w, &h);

    glViewport(0, 0, w, h);
    m_camera.setRatio((float)w / h);
}
