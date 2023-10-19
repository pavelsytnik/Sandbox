#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include "glad/glad.h"

class VertexBuffer {
public:
    VertexBuffer();
    ~VertexBuffer();
    void bind();
    void unbind();
    void setData(GLsizeiptr size, const void* data, GLenum usage);
    void attachAttributePointer(
        GLuint index,
        GLint size,
        GLenum type,
        GLboolean normalized,
        GLsizei stride,
        const void* pointer
    );
    GLuint id();
private:
    GLuint m_id{};
};

#endif
