#include "PlayScene.hpp"

#include <glm/glm.hpp>

#include "../glad/glad.h"

PlayScene::PlayScene() : m_world(10, 10, 10) {

    for (auto x = 0; x < m_world.getXSize(); ++x) {
        for (auto y = 0; y < m_world.getYSize(); ++y) {
            for (auto z = 0; z < m_world.getZSize(); ++z) {
                if (m_world.getBlock(x, y, z) == 1) {
                    m_mesh.addFace({x + .2f, y + .2f, z + .5f}, {0, 0});
                    m_mesh.addFace({x + .2f, y + .8f, z + .5f}, {0, 1});
                    m_mesh.addFace({x + .8f, y + .8f, z + .5f}, {1, 1});

                    m_mesh.addFace({x + .8f, y + .8f, z + .5f}, {1, 1});
                    m_mesh.addFace({x + .8f, y + .2f, z + .5f}, {1, 0});
                    m_mesh.addFace({x + .2f, y + .2f, z + .5f}, {0, 0});
                }
            }
        }
    }
    m_mesh.setVBO();
}

//PlayScene::~PlayScene() {}

void PlayScene::handleInput() {

}

void PlayScene::update() {

    if (m_world.changed()) {
        m_world.update();
        m_mesh.clear();

        for (auto x = 0; x < m_world.getXSize(); ++x) {
            for (auto y = 0; y < m_world.getYSize(); ++y) {
                for (auto z = 0; z < m_world.getZSize(); ++z) {
                    m_mesh.addFace({x + .1f, y + .1f, z + .5f}, {0, 0});
                    m_mesh.addFace({x + .1f, y + .9f, z + .5f}, {0, 1});
                    m_mesh.addFace({x + .9f, y + .9f, z + .5f}, {1, 1});
                    m_mesh.addFace({x + .9f, y + .1f, z + .5f}, {1, 0});
                }
            }
        }
    }
}

void PlayScene::render() {
    m_shader.use();
    m_shader.loadModelMatrix(glm::mat4(1.f));
    m_shader.loadViewMatrix(m_camera.getViewMatrix());
    m_shader.loadProjectionMatrix(m_camera.getProjectionMatrix());


    m_mesh.draw();

}
