#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <cstdlib>

#include <glm/glm.hpp>

#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "ElementBuffer.hpp"

using FloatBuffer = std::vector<GLfloat>;

enum class Front {
    AGAINST_AXIS = 0,
    FACING_AXIS
};

class Mesh {

public:
    Mesh();
    virtual ~Mesh() = default;

    void clear();
    void draw();
    void setData();
    std::size_t getBufferSize() const;

protected:
    void addVertex(const glm::vec3& pos, const glm::vec2& textureCoord);
    void addIndices(Front front);

private:
    //void setAttributePointers();

    VertexBuffer m_vbo;
    VertexArray m_vao;
    ElementBuffer m_ebo;

    FloatBuffer m_vertices;
    std::vector<GLuint> m_indices;
};

#endif
