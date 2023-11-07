#include "Entity.hpp"

#include "iostream"

#include "../World/World.hpp"

Entity::Entity(World& world) :
    //m_position(glm::vec3(world.getXSize() / 2, world.getYSize() + 2, world.getZSize() / 2)),
    m_acceleration(0.f),
    m_yaw(270.f),
    m_world(world) {

}

float Entity::getYaw() const {
    return m_yaw;
}

float Entity::getPitch() const {
    return m_pitch;
}

const glm::vec3& Entity::getAcceleration() const {
    return m_acceleration;
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
        m_acceleration = glm::normalize(direction);
    } else {
        //std::cout << "zero\n";
    }
}

void Entity::move(std::uint64_t dt) {
    auto k = 0.5f;
    if (glm::length(m_acceleration) != 0) {
        float delta = dt / 1000000.f / 1000.f;
        m_position += delta * 4 * m_acceleration;
        std::cout << glm::length(m_acceleration) << std::endl;
        std::cout << delta * k << std::endl << std::endl;
        //std::cout << m_position.x << std::endl;

        float i;
        if ((i = glm::length(m_acceleration)) > 0) {
            //std::cout << i << std::endl;
        }
        //m_acceleration *= 0.9f;
        if (glm::length(m_acceleration) - delta * k >= 0.f) {
            m_acceleration = (glm::length(m_acceleration) - delta * k) * glm::normalize(m_acceleration);
        } else {
            m_acceleration = glm::vec3(0.f);
        }


        //if (glm::length(m_acceleration) < 0.01f) {
            //m_acceleration = glm::vec3(0.f);
        //}
    }
}
