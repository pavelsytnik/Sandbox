#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/glm.hpp>

class World;

class Entity {
    
public:
    Entity(World& world);
    void move(float dt);

    float getYaw() const;
    float getPitch() const;

    const glm::vec3& getPosition() const;
    const glm::vec3& getForce() const;
    const glm::vec3& getVelocity() const;

    void setMotion(const glm::vec3& direction);

    // the following code will be rewritten because of excess access

    void setYaw(float angle);
    void setPitch(float angle);

    void setPosition(const glm::vec3& position);

    //

protected:
    glm::vec3 m_position;
    glm::vec3 m_velocity;
    glm::vec3 m_force;

    bool m_impulse;

    float m_yaw;
    float m_pitch;

    World& m_world;
};

#endif
