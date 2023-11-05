#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstdint>
#include <glm/glm.hpp>

class World;

class Entity {
    
public:
    Entity(World& world);
    void move(std::uint64_t dt);

protected:
    glm::vec3 m_position;
    float m_yaw;
    float m_pitch;
    glm::vec3 m_acceleration;
    World& m_world;
};

#endif
