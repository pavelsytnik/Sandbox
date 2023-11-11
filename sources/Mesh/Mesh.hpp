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
    //void addFace(const glm::vec3& pos, const glm::vec2& textureCoord);
    void clear();
    void draw();
    void setVBO();
    std::size_t getBufferSize() const;

protected:
    void addVertex(const glm::vec3& pos, const glm::vec2& textureCoord);

private:
    void setAttributePointers();

    VertexBuffer m_vbo;
    VertexArray m_vao;

    FloatBuffer m_vertices;
};

#endif
