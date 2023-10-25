#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include <glm/glm.hpp>

#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
//#include "Shaders/BasicShader.hpp"

using FloatBuffer = std::vector<GLfloat>;

class Mesh {

public:
    Mesh();
    void addFace(const glm::vec3& pos, const glm::vec2& textureCoord);
    void clear();
    void draw();
    void setVBO();
    std::size_t getBufferSize() const;

private:
    void setAttributePointers();

    VertexBuffer m_vbo;
    VertexArray m_vao;
    //BasicShader m_shader;

    FloatBuffer m_vertices;
};

#endif
