#include "Entity.hpp"

#include <iostream>
#include <cmath>

#include "../World/World.hpp"

Entity::Entity(World& world) :
    //m_position(glm::vec3(world.getXSize() / 2, world.getYSize() + 2, world.getZSize() / 2)),
    m_velocity(0.f),
    m_force(0.f),
    m_inertia(0.f),
    m_impulse(false),
    m_yaw(270.f),
    m_world(world) {

}

float Entity::getYaw() const {
    return m_yaw;
}

float Entity::getPitch() const {
    return m_pitch;
}

//const glm::vec3& Entity::getAcceleration() const {
    //return m_acceleration;
//}

const glm::vec3& Entity::getVelocity() const {
    return m_velocity;
}

const glm::vec3& Entity::getForce() const {
    return m_force;
}

const glm::vec3& Entity::getPosition() const {
    return m_position;
}

void Entity::setPitch(float angle) {
    m_pitch = angle;
}

void Entity::setYaw(float angle) {
    m_yaw = angle;
}

void Entity::setPosition(const glm::vec3& position) {
    m_position = position;
}

void Entity::setMotion(const glm::vec3& direction) {
    if (glm::length(direction) != 0) {
        m_force = glm::normalize(direction);
        //m_inertia = glm::length(m_velocity) != 0 ? glm::normalize(m_velocity) : glm::vec3(0.f);
        m_impulse = true;
    }
    else {
        m_force = glm::vec3(0.f);
        m_impulse = false;
    }
}

void Entity::move(std::uint64_t dt) {

    auto k = 0.5f;
    float delta = dt / 1000000.f / 1000.f;

    static float n = 0.f;


    m_position += delta * 15 * m_velocity;

    glm::vec3 dif = m_velocity - m_force;
    if (glm::length(dif) != 0.f && glm::length(dif) - delta * k >= 0.f) {
        dif = (glm::length(dif) - delta * k) * glm::normalize(dif);
    } else {
        dif = glm::vec3(0.f);
    }
    m_velocity = m_force + dif;
    //m_impulse = false;
}
