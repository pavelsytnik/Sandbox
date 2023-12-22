#include "Ray.hpp"

Ray::Ray(const glm::vec3& origin, const glm::vec3& direction) :
    origin(origin),
    direction(direction),
    end(origin)
{}

void Ray::step(float a) {
    end += direction * a;
}
