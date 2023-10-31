#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

class Camera {

public:
    Camera(glm::float32 ratio = 1.f);

    void setPosition(const glm::vec3& position);
    void setDirection(const glm::vec3& direction);
    const glm::vec3& getPosition() const;
    const glm::vec3& getDirection() const;

    void setFOV(glm::float32 fov);
    void setRatio(glm::float32 ratio);
    glm::float32 getFOV() const;
    glm::float32 getRatio() const;

    const glm::mat4& getViewMatrix() const;
    const glm::mat4& getProjectionMatrix() const;

private:
    glm::vec3 m_position;
    glm::vec3 m_direction;
    glm::vec3 m_axis;

    glm::float32 m_fov;
    glm::float32 m_ratio;

    glm::mat4 m_viewMatrix;
    glm::mat4 m_projectionMatrix;
};

#endif
