#ifndef UNIFORM_LOADER_HPP
#define UNIFORM_LOADER_HPP

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"

void loadMatrix4(GLuint location, const glm::mat4& matrix);

#endif
