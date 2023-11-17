#include "ElementBuffer.hpp"

ElementBuffer::ElementBuffer() {
    glGenBuffers(1, &m_id);
}

ElementBuffer::~ElementBuffer() {
    glDeleteBuffers(1, &m_id);
}

void ElementBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void ElementBuffer::setData(GLsizeiptr size, const void* data, GLenum usage) {
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
}
