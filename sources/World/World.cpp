#include "World.hpp"

#include "../Registry/Registry.hpp"
#include "../Block/Block.hpp"

World::World(std::uint32_t x, std::uint32_t y, std::uint32_t z) :
    m_blocks(new std::uint8_t[x * y * z]),
    m_xSize(x), m_ySize(y), m_zSize(z),
    m_player(*this)
{
    for (int i = 0; i < x * y * z; i++) {
        m_blocks[i] = 2;
    }

    for (int _y = 0; _y < y; _y++) {
        for (int _x = _y; _x < x - _y; _x++) {
            for (int _z = _y; _z < z - _y; _z++) {
                //setBlock(Blocks::getInstance().GRASS, _x, _y, _z);
                //std::cout << int(getBlock(_x, _y, _z).getID()) << std::endl;
            }
        }
    }

    m_player.m_position = glm::vec3(getXSize() / 2, getYSize() + 2, getZSize() / 2);
}

World::~World() {
    delete[] m_blocks;
}

const Block& World::getBlock(std::int32_t x, std::int32_t y, std::int32_t z) const {
    auto id = m_blocks[y * m_xSize * m_zSize + x * m_zSize + z];
    for (const auto& block : Registry::getBlocks()) {
        if (block->getID() == id) {
            //std::cout << x << y << z << ((id == 2) ? "grass" : "air") << std::endl;
            return *block;
        }
    }
    throw 666;
}

void World::setBlock(const Block& block, std::int32_t x, std::int32_t y, std::int32_t z) {
    m_blocks[m_zSize * (y * m_xSize + x) + z] = block.getID();
}

void World::update(float dt) {
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
