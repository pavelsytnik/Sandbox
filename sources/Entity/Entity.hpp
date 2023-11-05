#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/glm.hpp>

class World;

class Entity {
    
public:
    Entity(World& world);
    void update() = 0;

protected:
    glm::vec3 m_position;
    float m_yaw;
    float m_pitch;
    glm::vec3 m_acceleration;
};

#endif
