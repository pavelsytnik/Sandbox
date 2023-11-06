#include "Entity.hpp"

#include "../World/World.hpp"

Entity::Entity(World& world) :
    m_position(glm::vec3(world.getXSize() / 2, world.getYSize() + 2, world.getZSize() / 2)),
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

void Entity::move(std::uint64_t dt) {

}
