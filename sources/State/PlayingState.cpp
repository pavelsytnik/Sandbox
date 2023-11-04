#include <iostream>
#include <cmath>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "PlayingState.hpp"
#include "../Application.hpp"

PlayingState::PlayingState(Application& app) :
    State(app),
    m_world(50, 25, 50),
    m_player(m_world.getPlayer()),
    m_texture("resources/images/blocks.png"),
    m_buttons(MouseButtonMappings::getInstance()),
    m_keys(KeyMappings::getInstance()),
    m_mouse(app.getMouse())
{
    for (auto x = 0; x < m_world.getXSize(); ++x) {
        for (auto y = 0; y < m_world.getYSize(); ++y) {
            for (auto z = 0; z < m_world.getZSize(); ++z) {
                if (m_world.getBlock(x, y, z) == 1) {
                    m_mesh.addFace({x + .2f, y + .2f, z + .5f}, {0, 240.f / 256});
                    m_mesh.addFace({x + .2f, y + .8f, z + .5f}, {0, 1});
                    m_mesh.addFace({x + .8f, y + .8f, z + .5f}, {1.f / 16, 1});

                    m_mesh.addFace({x + .8f, y + .8f, z + .5f}, {1.f / 16, 1});
                    m_mesh.addFace({x + .8f, y + .2f, z + .5f}, {1.f / 16, 240.f / 256});
                    m_mesh.addFace({x + .2f, y + .2f, z + .5f}, {0, 240.f / 256});
                }
            }
        }
    }
    m_mesh.setVBO();

    auto& yaw = m_world.getPlayer().yaw;
    auto& pitch = m_world.getPlayer().pitch;
    m_camera.setPosition(m_world.getPlayer().position);
    m_camera.setDirection(
        glm::vec3(
            std::cos(glm::radians(yaw)) * std::cos(glm::radians(pitch)),
            std::sin(glm::radians(pitch)),
            std::sin(glm::radians(yaw)) * std::cos(glm::radians(pitch))
        )
    );
    SDL_SetRelativeMouseMode(SDL_TRUE);
    //SDL_GL_SetSwapInterval(0);
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

    m_player.yaw += 0.15 * m_mouse.getDX();
    m_player.pitch -= 0.15 * m_mouse.getDY();
}

void PlayingState::keyboardInput() {
    if (m_keys.FORWARD->heldDown()) {
        m_player.acceleration.x += std::cos(glm::radians(m_player.yaw));
        m_player.acceleration.z += std::sin(glm::radians(m_player.yaw));
    }
    if (m_keys.BACKWARD->heldDown()) {
        m_player.acceleration.x -= std::cos(glm::radians(m_player.yaw));
        m_player.acceleration.z -= std::sin(glm::radians(m_player.yaw));
    }
    if (m_keys.LEFT->heldDown()) {
        m_player.acceleration.x -= std::cos(glm::radians(m_player.yaw + 90));
        m_player.acceleration.z -= std::sin(glm::radians(m_player.yaw + 90));
    }
    if (m_keys.RIGHT->heldDown()) {
        m_player.acceleration.x += std::cos(glm::radians(m_player.yaw + 90));
        m_player.acceleration.z += std::sin(glm::radians(m_player.yaw + 90));
    }
    if (m_keys.UP->heldDown()) {
        m_player.acceleration.y += 1;
    }
    if (m_keys.DOWN->heldDown()) {
        m_player.acceleration.y -= 1;
    }

    if (glm::length(m_player.acceleration) != 0.f) {
        m_player.position += 0.06f * glm::normalize(m_player.acceleration);
        m_player.acceleration = glm::vec3(0.f, 0.f, 0.f);
    }
}

void PlayingState::update() {

    if (m_world.changed()) {
        m_world.update();
        m_mesh.clear();

        for (auto x = 0; x < m_world.getXSize(); ++x) {
            for (auto y = 0; y < m_world.getYSize(); ++y) {
                for (auto z = 0; z < m_world.getZSize(); ++z) {
                    if (m_world.getBlock(x, y, z) == 1) {
                        m_mesh.addFace({x + .2f, y + .2f, z + .5f}, {0, 240.f / 256});
                        m_mesh.addFace({x + .2f, y + .8f, z + .5f}, {0, 1});
                        m_mesh.addFace({x + .8f, y + .8f, z + .5f}, {1.f / 16, 1});

                        m_mesh.addFace({x + .8f, y + .8f, z + .5f}, {1.f / 16, 1});
                        m_mesh.addFace({x + .8f, y + .2f, z + .5f}, {1.f / 16, 240.f / 256});
                        m_mesh.addFace({x + .2f, y + .2f, z + .5f}, {0, 240.f / 256});
                    }
                }
            }
        }
        m_mesh.setVBO();
    }
    m_camera.setPosition(m_player.position);
    m_camera.setDirection(
        glm::vec3(
            std::cos(glm::radians(m_player.yaw)) * std::cos(glm::radians(m_player.pitch)),
            std::sin(glm::radians(m_player.pitch)),
            std::sin(glm::radians(m_player.yaw)) * std::cos(glm::radians(m_player.pitch))
        )
    );
}

void PlayingState::render() {
    glBindTexture(GL_TEXTURE_2D, m_texture.getID());
    m_shader.use();
    m_shader.loadModelMatrix(glm::mat4(1.f));
    m_shader.loadViewMatrix(m_camera.getViewMatrix());
    m_shader.loadProjectionMatrix(m_camera.getProjectionMatrix());


    m_mesh.draw();

}

void PlayingState::resize() {
    int w, h;
    SDL_GetWindowSize(m_app.getContext().getWindow(), &w, &h);

    glViewport(0, 0, w, h);
    m_camera.setRatio((float)w / h);
}
