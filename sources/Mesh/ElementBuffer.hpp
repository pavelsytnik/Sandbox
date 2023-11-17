#ifndef ELEMENT_BUFFER_HPP
#define ELEMENT_BUFFER_HPP

#include <glad/glad.h>

class ElementBuffer {

public:
    ElementBuffer();
    ~ElementBuffer();
    void bind() const;
    void setData(GLsizeiptr size, const void* data, GLenum usage);

private:
    GLuint m_id;
};

#endif
