#include "Entity.hpp"

#include <iostream>
#include <cmath>
#include <vector>

#include "../World/World.hpp"

#include <glm/gtx/vector_angle.hpp>

Entity::Entity(World& world, const AABB& boundingBox, const glm::vec3& position) :
    m_position(position),
    m_velocity(0.f),
    m_force(0.f),
    m_impulse(false),
    m_yaw(270.f),
    m_pitch(0.f),
    m_boundingBox{
        position.x + boundingBox.minX,
        position.y + boundingBox.minY,
        position.z + boundingBox.minZ,

        position.x + boundingBox.maxX,
        position.y + boundingBox.maxY,
        position.z + boundingBox.maxZ
    },
    m_world(world) {

}

float Entity::getYaw() const {
    return m_yaw;
}

float Entity::getPitch() const {
    return m_pitch;
}

AABB Entity::getBoundingBox() const {
    return m_boundingBox;
}

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
        m_impulse = glm::length(m_force) == 0;
        m_force = glm::normalize(direction);
    } else {
        m_impulse = false;
        m_force = glm::vec3(0.f);
    }
}

void Entity::move(float dt) {

    auto k = 5.f;

    glm::vec3 dif = m_velocity - m_force;

    if (m_impulse && glm::length(m_velocity) == 0) {
        m_velocity = m_force;

    } else if (m_impulse) {
        m_velocity = glm::mix(m_velocity, m_force, std::min(1.f, 0.5f / glm::length(dif)));
    // or
    //  m_velocity = glm::mix(m_velocity, m_force, 0.2f);

    } else {

        if (glm::length(dif) != 0.f && glm::length(dif) - dt * k >= 0.f) {
            dif = (glm::length(dif) - dt * k) * glm::normalize(dif);
        } else {
            dif = glm::vec3(0.f);
        }

        m_velocity = m_force + dif;
    }

    auto vec = dt * 10 * m_velocity;

    //auto box = m_boundingBox;
    //box.move(vec.x, vec.y, vec.z);
    auto boxes = m_world.getSurroundingBlocks(m_boundingBox);

    float x = vec.x, y = vec.y, z = vec.z;

    for (const auto& box : boxes) {
        x = m_boundingBox.clipXCollide(box, x);
    }
    m_boundingBox.move(x, .0f, .0f);

    for (const auto& box : boxes) {
        y = m_boundingBox.clipYCollide(box, y);
    }
    m_boundingBox.move(.0f, y, .0f);

    for (const auto& box : boxes) {
        z = m_boundingBox.clipZCollide(box, z);
    }
    m_boundingBox.move(.0f, .0f, z);
    if (glm::length(m_velocity) != 0)
        std::cout << x << ", " << y << ", " << z << std::endl;
    m_position += glm::vec3(x, y, z);
    //m_boundingBox.move(vec.x, vec.y, vec.z);

    m_impulse = false;
}
