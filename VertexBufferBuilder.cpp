#include "VertexBufferBuilder.hpp"

void VertexBufferBuilder::addFace(const glm::vec3& pos, const glm::vec2& textureCoord) {
    m_buffer.push_back(pos.x);
    m_buffer.push_back(pos.y);
    m_buffer.push_back(pos.z);

    m_buffer.push_back(textureCoord.x);
    m_buffer.push_back(textureCoord.y);
}

std::vector<GLfloat> VertexBufferBuilder::getBuffer() const {
    return m_buffer;
}
