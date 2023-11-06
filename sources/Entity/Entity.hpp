#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstdint>
#include <glm/glm.hpp>

class World;

class Entity {

    friend class World;
    
public:
    Entity(World& world);
    void move(std::uint64_t dt);

    float getYaw() const;
    float getPitch() const;

    const glm::vec3& getPosition() const;
    const glm::vec3& getAcceleration() const;

protected:
    glm::vec3 m_position;
    glm::vec3 m_acceleration;

    float m_yaw;
    float m_pitch;

    World& m_world;
};

#endif