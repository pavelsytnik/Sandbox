#ifndef RAY_HPP
#define RAY_HPP

#include <glm/glm.hpp>

struct Ray {
    glm::vec3 origin;
    glm::vec3 direction;
    glm::vec3 end;

    Ray(const glm::vec3& origin, const glm::vec3& direction);
    void step(float a);
};

#endif
