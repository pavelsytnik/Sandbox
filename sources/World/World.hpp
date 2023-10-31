#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>

class World {

public:
    World(std::uint32_t x, std::uint32_t y, std::uint32_t z);
    ~World();
    std::uint8_t getBlock(std::uint32_t x, std::uint32_t y, std::uint32_t z) const;
    void setBlock(std::uint8_t block, std::uint32_t x, std::uint32_t y, std::uint32_t z);
    void update();
    bool changed() const;

    std::uint32_t getXSize() const;
    std::uint32_t getYSize() const;
    std::uint32_t getZSize() const;

private:
    std::uint8_t* m_blocks;
    std::uint32_t m_xSize, m_ySize, m_zSize;

    bool m_changed;
};

#endif