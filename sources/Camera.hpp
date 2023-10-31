#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

class Camera {

public:
    Camera();

    void setPosition(const glm::vec3& position);
    void setDirection(const glm::vec3& direction);
    const glm::vec3& getPosition() const;
    const glm::vec3& getDirection() const;

    const glm::mat4& getViewMatrix() const;
    const glm::mat4& getProjectionMatrix() const;

private:
    glm::vec3 m_position;
    glm::vec3 m_direction;
    glm::vec3 m_axis;

    glm::mat4 m_viewMatrix;
    glm::mat4 m_projectionMatrix;
};

#endif
