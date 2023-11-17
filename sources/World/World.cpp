#include "World.hpp"

World::World(std::uint32_t x, std::uint32_t y, std::uint32_t z) :
    m_blocks(new std::uint8_t[x * y * z]),
    m_xSize(x), m_ySize(y), m_zSize(z),
    m_player(*this)
{
    for (int i = 0; i < x * y * z; i++) {
        m_blocks[i] = 0;
    }
    for (int _y = 0; _y < y; _y++) {
        for (int _x = _y; _x < x; _x++) {
            for (int _z = _y; _z < z; _z++) {
                setBlock(1, _x, _y, _z);
            }
        }
    }

    m_player.m_position = glm::vec3(getXSize() / 2, getYSize() + 2, getZSize() / 2);
}

World::~World() {
    delete[] m_blocks;
}

std::uint8_t World::getBlock(std::uint32_t x, std::uint32_t y, std::uint32_t z) const {
    return m_blocks[y * m_xSize * m_zSize + x * m_zSize + z];
}

void World::setBlock(std::uint8_t block, std::uint32_t x, std::uint32_t y, std::uint32_t z) {
    m_blocks[m_zSize * (y * m_xSize + x) + z] = block;
}

void World::update(std::uint64_t dt) {
    m_player.move(dt);
}

Player& World::getPlayer() {
    return m_player;
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
