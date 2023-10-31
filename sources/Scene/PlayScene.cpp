#include "PlayScene.hpp"



#include <glm/glm.hpp>

#include <glad/glad.h>

PlayScene::PlayScene(Context& context) :
    m_context{context},
    m_world(10, 10, 10),
    m_texture("resources/images/blocks.png") {

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

void PlayScene::render() {
    glBindTexture(GL_TEXTURE_2D, m_texture.getID());
    m_shader.use();
    m_shader.loadModelMatrix(glm::mat4(1.f));
    m_shader.loadViewMatrix(m_camera.getViewMatrix());
    m_shader.loadProjectionMatrix(m_camera.getProjectionMatrix());


    m_mesh.draw();

}

void PlayScene::resize() {
    GLint w, h;
    SDL_GetWindowSize(m_context.getWindow(), &w, &h);
    m_camera.setRatio((float)w / h);
}
