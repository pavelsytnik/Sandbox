#include "World.hpp"

World::World(std::uint32_t x, std::uint32_t y, std::uint32_t z) :
    m_blocks(new std::uint8_t[x * y * z]),
    m_xSize(x), m_ySize(y), m_zSize(z),
    m_changed(true)
{
    for (int i = 0; i < x * y * z; i++) {
        m_blocks[i] = 1;
    }
}

World::~World() {
    delete[] m_blocks;
}

std::uint8_t World::getBlock(std::uint32_t x, std::uint32_t y, std::uint32_t z) const {
    return m_blocks[y * m_xSize * m_zSize + x * m_zSize + z];
}

void World::setBlock(std::uint8_t block, std::uint32_t x, std::uint32_t y, std::uint32_t z) {
    m_blocks[m_zSize * (y * m_xSize + x) + z] = block;
    m_changed = true;
}

void World::update() {
    m_changed = false;
}

bool World::changed() const {
    return m_changed;
}

std::uint32_t World::getXSize() const {
    return m_xSize;
}

std::uint32_t World::getYSize() const {
    return m_ySize;
}

std::uint32_t World::getZSize() const {
    return m_zSize;
}
