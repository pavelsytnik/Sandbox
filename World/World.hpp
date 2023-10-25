#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>

#include "Tessellator.hpp"
#include "Camera.hpp"

class World {
public:
    World(std::uint32_t x, std::uint32_t y, std::uint32_t z);
    ~World();
    Camera& getCamera();
    std::uint8_t getBlock(std::uint32_t x, std::uint32_t y, std::uint32_t z);
    void setBlock(std::uint8_t block, std::uint32_t x, std::uint32_t y, std::uint32_t z);
    void redraw();
    bool changed();
private:
    std::uint8_t* blocks;
    std::uint32_t xSize, ySize, zSize;
    Camera m_camera;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    Tessellator m_tessellator;
    bool m_changed;
};

#endif
