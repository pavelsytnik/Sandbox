#include "UniformLoader.hpp"

void loadMatrix4(GLuint location, const glm::mat4& matrix) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}
