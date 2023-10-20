#include "Camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() :
    m_position{0.f, 0.f, 0.f},
    m_direction{0.f, 0.f, -1.f},
    m_axis{0.f, 1.f, 0.f}
{
}

void Camera::setPosition(glm::vec3 position) {
    m_position = position;
}

void Camera::setDirection(glm::vec3 direction) {
    m_direction = glm::normalize(direction);
}

const glm::vec3& Camera::getPosition() const {
    return m_position;
}

const glm::vec3& Camera::getDirection() const {
    return m_direction;
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(m_position, m_position + m_direction, m_axis);
}
