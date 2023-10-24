#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

#include "VertexBuffer.hpp"
#include "VertexArray.hpp"

using FloatBuffer = std::vector<GLfloat>;

class Mesh {

public:
    Mesh();
    void addBufferData(const FloatBuffer& data);
    void clear();
    std::size_t getBufferSize() const;

private:
    void setAttributePointers();

    VertexBuffer m_vbo;
    VertexArray m_vao;

    FloatBuffer m_vertices;
};

#endif
