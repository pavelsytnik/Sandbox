#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include <glm/glm.hpp>

#include "VertexBuffer.hpp"
#include "VertexArray.hpp"

using FloatBuffer = std::vector<GLfloat>;

class Mesh {

public:
    Mesh();
    void addFace(const glm::vec3& pos, const glm::vec2& textureCoord);
    void clear();
    std::size_t getBufferSize() const;

private:
    void setAttributePointers();

    VertexBuffer m_vbo;
    VertexArray m_vao;

    FloatBuffer m_vertices;
};

#endif
