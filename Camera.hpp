#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

class Camera {
public:
    Camera();
    void setPosition(glm::vec3 position);
    void setDirection(glm::vec3 direction);
    const glm::vec3& getPosition() const;
    const glm::vec3& getDirection() const;
    glm::mat4 getViewMatrix() const;

private:
    glm::vec3 m_position;
    glm::vec3 m_direction;
    glm::vec3 m_axis;

    //glm::mat4 m_view;
};

#endif
