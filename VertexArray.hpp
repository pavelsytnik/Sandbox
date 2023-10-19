#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "glad/glad.h"

class VertexArray {
public:
    VertexArray();
    ~VertexArray();
    void bind();
    void unbind();
    GLuint id();
private:
    GLuint m_id;
};

#endif
