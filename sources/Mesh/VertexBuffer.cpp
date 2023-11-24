#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer() {
    glGenBuffers(1, &m_id);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &m_id);
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

//void VertexBuffer::unbind() {
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//}

void VertexBuffer::setData(GLsizeiptr size, const void* data, GLenum usage) {
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    //unbind();
}

void VertexBuffer::attachAttributePointer(
    GLuint index,
    GLint size,
    GLenum type,
    GLboolean normalized,
    GLsizei stride,
    const void* pointer
) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

//GLuint VertexBuffer::getID() {
//    return m_id;
//}
