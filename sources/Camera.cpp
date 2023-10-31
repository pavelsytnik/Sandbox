#include "Camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::float32 ratio) :
    m_position{0.f, 0.f, 0.f},
    m_direction{0.f, 0.f, -1.f},
    m_axis{0.f, 1.f, 0.f},
    m_ratio{ratio},
    m_fov{glm::radians(70.f)},
    m_viewMatrix{glm::lookAt(m_position, m_position + m_direction, m_axis)},
    m_projectionMatrix{glm::perspective(m_fov, m_ratio, 0.1f, 100.f)}
{
    //m_viewMatrix = glm::rotate(m_viewMatrix, glm::radians(60.f), glm::vec3(0, 1, 0));
}

void Camera::setPosition(const glm::vec3& position) {
    m_position = position;
    m_viewMatrix = glm::lookAt(m_position, m_position + m_direction, m_axis);
}

void Camera::setDirection(const glm::vec3& direction) {
    m_direction = glm::normalize(direction);
    m_viewMatrix = glm::lookAt(m_position, m_position + m_direction, m_axis);
}

void Camera::setRatio(glm::float32 ratio) {
    m_ratio = ratio;
    m_projectionMatrix = glm::perspective(m_fov, m_ratio, 0.1f, 100.f);
}

void Camera::setFOV(glm::float32 fov) {
    m_fov = fov;
    m_projectionMatrix = glm::perspective(m_fov, m_ratio, 0.1f, 100.f);
}

const glm::vec3& Camera::getPosition() const {
    return m_position;
}

const glm::vec3& Camera::getDirection() const {
    return m_direction;
}

glm::float32 Camera::getRatio() const {
    return m_ratio;
}

glm::float32 Camera::getFOV() const {
    return m_fov;
}

const glm::mat4& Camera::getViewMatrix() const {
    return m_viewMatrix;
}

const glm::mat4& Camera::getProjectionMatrix() const {
    return m_projectionMatrix;
}
