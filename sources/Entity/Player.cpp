#include "Player.hpp"
#include "../Physics/AABB.hpp"

Player::Player(World& world, const glm::vec3& position) :
    Entity(world, {-.3f, .0f, -.3f, .3f, 1.8f, .3f}, position) {

}

//void Player::setYaw(float yaw) {
    //m_yaw = yaw;
//}

//void Player::setPitch(float pitch) {
    //m_pitch = pitch;
//}

//void Player::setAcceleration(const glm::vec3& dir) {
    //m_acceleration = dir;
//}
