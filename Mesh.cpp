#include "Mesh.hpp"

Mesh::Mesh() {
    setAttributePointers();
}

std::size_t Mesh::getBufferSize() const {
    return m_vertices.size();
}

void Mesh::addBufferData(const FloatBuffer& data) {
    m_vbo.setData(m_vertices.size() * sizeof(GLfloat), m_vertices.data(), GL_STATIC_DRAW);
}

void Mesh::clear() {
    m_vertices.clear();

    m_vao.bind();
    m_vbo.bind();

    m_vbo.setData(0, nullptr, GL_STATIC_DRAW);

    m_vbo.unbind();
    m_vao.unbind();
}

inline void Mesh::setAttributePointers() {
    m_vao.bind();
    m_vbo.bind();

    glEnableVertexAttribArray(0);
    m_vbo.attachAttributePointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    m_vbo.attachAttributePointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

    m_vbo.unbind();
    m_vao.unbind();
}
