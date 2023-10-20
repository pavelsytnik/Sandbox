#include "World.hpp"

#include <glm/gtc/type_ptr.hpp>

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

World::World(std::uint32_t x, std::uint32_t y, std::uint32_t z) :
    blocks(new std::uint8_t[x * y * z]),
    xSize(x), ySize(y), zSize(z),
    m_changed(true)
{
    for (int i = 0; i < x * y * z; i++) {
        blocks[i] = 1;
    }

    model = glm::mat4(1.f);
    projection = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 10.f);

    m_camera.setPosition(glm::vec3(2.f, 2.f, 7.f));
    //m_camera.setDirection(glm::vec3(-0.5f, -0.5f, -0.5f));
    m_camera.setDirection(glm::vec3(0.0f, 0.0f, -1.0f));
    view = m_camera.getViewMatrix();
    view = glm::rotate(view, glm::radians(40.f), glm::vec3(0.f, 1.f, 0.f));



}

World::~World() {
    delete[] blocks;
}

Camera& World::getCamera() {
    return m_camera;
}

std::uint8_t World::getBlock(std::uint32_t x, std::uint32_t y, std::uint32_t z) {
    return blocks[y * xSize * zSize + x * zSize + z];
}

void World::setBlock(std::uint8_t block, std::uint32_t x, std::uint32_t y, std::uint32_t z) {
    blocks[zSize * (y * xSize + x) + z] = block;
}

bool World::changed() {
    return m_changed;
}

void World::redraw() {
    for (int i = 0; i < ySize; i++) {
        for (int j = 0; j < xSize; j++) {
            for (int k = 0; k < zSize; k++) {
                if (blocks[zSize * (i * xSize + j) + k] == 1) {
                    std::cout << j << ", " << i << ", " << k << std::endl;
                    m_tessellator.addVertex(j, i, k);
                    m_tessellator.addTextureCoordinate(0, 0);
                    m_tessellator.addVertex(j + 0.5f, i, k);
                    m_tessellator.addTextureCoordinate(0.5f, 0);
                    m_tessellator.addVertex(j, i + 0.5f, k);
                    m_tessellator.addTextureCoordinate(0, 0.5f);
                }
            }
        }
    }
    m_tessellator.getShader().use();
    glUniformMatrix4fv(m_tessellator.getModelMatrixLocation(), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(m_tessellator.getViewMatrixLocation(), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(m_tessellator.getProjectionMatrixLocation(), 1, GL_FALSE, glm::value_ptr(projection));
    m_tessellator.flush();
    m_changed = false;
}
