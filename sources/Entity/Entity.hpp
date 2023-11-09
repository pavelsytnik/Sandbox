#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstdint>
#include <glm/glm.hpp>

class World;

class Entity {

    //friend class World;
    
public:
    Entity(World& world);
    void move(std::uint64_t dt);

    float getYaw() const;
    float getPitch() const;

    const glm::vec3& getPosition() const;
    //const glm::vec3& getAcceleration() const;
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
    //glm::vec3 m_acceleration;
    glm::vec3 m_velocity;
    glm::vec3 m_force;

    glm::vec3 m_inertia;
    
    //float m_speed;
    bool m_impulse;

    float m_yaw;
    float m_pitch;

    World& m_world;
};

#endif
