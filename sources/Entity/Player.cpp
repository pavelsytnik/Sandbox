#include "Player.hpp"

Player::Player(World& world) : Entity(world) {

}

void Player::setYaw(float yaw) {
    m_yaw = yaw;
}

void Player::setPitch(float pitch) {
    m_pitch = pitch;
}

void Player::setAcceleration(const glm::vec3& dir) {
    m_acceleration = dir;
}
