#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>

#include "../Entity/Player.hpp"

class Block;

class World {

public:
    World(std::uint32_t x, std::uint32_t y, std::uint32_t z);
    ~World();

    const Block& getBlock(std::int32_t x, std::int32_t y, std::int32_t z) const;
    void setBlock(const Block& block, std::int32_t x, std::int32_t y, std::int32_t z);

    void update(float dt);

    Player& getPlayer();

    std::uint32_t getXSize() const;
    std::uint32_t getYSize() const;
    std::uint32_t getZSize() const;

private:
    std::uint8_t* m_blocks;
    std::uint32_t m_xSize, m_ySize, m_zSize;

    Player m_player;
};

#endif
