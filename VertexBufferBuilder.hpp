#ifndef VERTEX_BUFFER_BUILDER_HPP
#define VERTEX_BUFFER_BUILDER_HPP

#include <vector>

#include "glad/glad.h"

#include <glm/glm.hpp>

class VertexBufferBuilder {

public:
    void addFace(const glm::vec3& pos, const glm::vec2& textureCoord);
    std::vector<GLfloat> getBuffer() const;

private:
    std::vector<GLfloat> m_buffer;
};

#endif
