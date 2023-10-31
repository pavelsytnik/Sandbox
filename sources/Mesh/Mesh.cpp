#include "Mesh.hpp"

Mesh::Mesh() {
    setAttributePointers();
}

std::size_t Mesh::getBufferSize() const {
    return m_vertices.size();
}

void Mesh::addFace(const glm::vec3& pos, const glm::vec2& textureCoord) {
    m_vertices.push_back(pos.x);
    m_vertices.push_back(pos.y);
    m_vertices.push_back(pos.z);

    m_vertices.push_back(textureCoord.x);
    m_vertices.push_back(textureCoord.y);
}

void Mesh::clear() {
    m_vertices.clear();

    //m_vao.bind();
    m_vbo.setData(0, nullptr, GL_STATIC_DRAW);
    //m_vao.unbind();
}

void Mesh::setVBO() {
    m_vbo.setData(m_vertices.size() * sizeof(GLfloat), m_vertices.data(), GL_STATIC_DRAW);
}

void Mesh::draw() {

    //m_vbo.setData(m_vertices.size() * sizeof(GLfloat), m_vertices.data(), GL_STATIC_DRAW);

    //m_shader.use();
    m_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
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
