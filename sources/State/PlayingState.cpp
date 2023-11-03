#include "PlayingState.hpp"

#include "../Application.hpp"

#include <glm/glm.hpp>

#include <glad/glad.h>

#include <iostream>
#include <cmath>

PlayingState::PlayingState(Application& app) :
    State(app),
    m_world(10, 10, 10),
    m_texture("resources/images/blocks.png"),
    m_keys(Registry::getKeys()),
    m_listeners(Registry::getListeners()) {

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
}

//PlayScene::~PlayScene() {}

void PlayingState::handleEvent(const SDL_Event& event) {
    State::handleEvent(event);
    if (event.type == SDL_MOUSEMOTION) {
        m_world.getPlayer().yaw += 0.2f * event.motion.xrel;
        m_world.getPlayer().pitch -= 0.2f * event.motion.yrel;
    }
}

void PlayingState::handleInput() {
    static auto& keys = KeyMappings::getInstance();
    auto& player = m_world.getPlayer();

    //for (auto listener : m_listeners) {
        //listener(m_world);
    //}

   

    if (keys.FORWARD->heldDown()) {
        player.position += 0.06f * glm::vec3(
            std::cos(glm::radians(player.yaw)),
            0.f,
            std::sin(glm::radians(player.yaw))
        );
    } else if (keys.BACKWARD->heldDown()) {
        player.position -= 0.06f * glm::vec3(
            std::cos(glm::radians(player.yaw)),
            0.f,
            std::sin(glm::radians(player.yaw))
        );
    } else if (keys.LEFT->heldDown()) {
        player.position -= 0.06f * glm::normalize(glm::cross(
            glm::vec3(
                std::cos(glm::radians(player.yaw)),
                0.f,
                std::sin(glm::radians(player.yaw))), glm::vec3(0.f, 1.f, 0.f)));
    } else if (keys.RIGHT->heldDown()) {
    player.position += 0.06f * glm::normalize(glm::cross(
        glm::vec3(
            std::cos(glm::radians(player.yaw)),
            0.f,
            std::sin(glm::radians(player.yaw))), glm::vec3(0.f, 1.f, 0.f)));
    } else if (keys.UP->heldDown()) {
        player.position += 0.06f * glm::vec3(0.f, 1.f, 0.f);
    } else if (keys.DOWN->heldDown()) {
        player.position -= 0.06f * glm::vec3(0.f, 1.f, 0.f);
    }
    m_camera.setPosition(player.position);
    m_camera.setDirection(
        glm::vec3(
            std::cos(glm::radians(player.yaw)) * std::cos(glm::radians(player.pitch)),
            std::sin(glm::radians(player.pitch)),
            std::sin(glm::radians(player.yaw)) * std::cos(glm::radians(player.pitch))
        )
    );
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
