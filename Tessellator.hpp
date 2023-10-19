#ifndef TESSELLATOR_HPP
#define TESSELLATOR_HPP

#include <vector>

#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"

using FloatBuffer = std::vector<GLfloat>;

class Tessellator {
public:
    Tessellator();
    ~Tessellator() = default;
    void flush();
    void clear();
    void addVertex(GLfloat x, GLfloat y, GLfloat z);
    void addTextureCoordinate(GLfloat u, GLfloat v);
    std::size_t getBufferSize();
    GLuint vbo();
    GLuint vao();
private:
    VertexBuffer m_vbo;
    VertexArray m_vao;
    Shader m_shader;

    FloatBuffer m_vertices;
};

#endif
