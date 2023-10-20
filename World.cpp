#include "World.hpp"

World::World(std::uint32_t x, std::uint32_t y, std::uint32_t z) :
    blocks(new std::uint8_t[x * y * z]),
    xSize(x), ySize(y), zSize(z),
    m_changed(true)
{
    for (int i = 0; i < x * y * z; i++) {
        blocks[i] = 1;
    }
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
    m_tessellator.flush();
    m_changed = false;
}
