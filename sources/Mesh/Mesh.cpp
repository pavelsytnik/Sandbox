#include "Mesh.hpp"

Mesh::Mesh() {
    m_vao.bind();
    m_vbo.bind();
    m_ebo.bind();

    glEnableVertexAttribArray(0);
    m_vbo.attachAttributePointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);

    glEnableVertexAttribArray(1);
    m_vbo.attachAttributePointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
}

std::size_t Mesh::getBufferSize() const {
    return m_vertices.size();
}

void Mesh::clear() {
    m_vertices.clear();

    m_vbo.setData(0, nullptr, GL_STATIC_DRAW);
}

void Mesh::setData() {
    m_vbo.setData(m_vertices.size() * sizeof(GLfloat), m_vertices.data(), GL_STATIC_DRAW);
    m_ebo.setData(m_indices.size() * sizeof(GLuint), m_indices.data(), GL_STATIC_DRAW);
}

void Mesh::draw() {

    m_vao.bind();
    //glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
    //m_vao.unbind();
}

//inline void Mesh::setAttributePointers() {
//    m_vao.bind();
//    m_vbo.bind();
//    m_ebo.bind();
//
//    glEnableVertexAttribArray(0);
//    m_vbo.attachAttributePointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//
//    glEnableVertexAttribArray(1);
//    m_vbo.attachAttributePointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//
//    //m_vbo.unbind();
//    //m_vao.unbind();
//}

void Mesh::addVertex(const glm::vec3& pos, const glm::vec2& textureCoord) {
    m_vertices.push_back(pos.x);
    m_vertices.push_back(pos.y);
    m_vertices.push_back(pos.z);

    m_vertices.push_back(textureCoord.x);
    m_vertices.push_back(textureCoord.y);
}

void Mesh::addIndices(Front front) {
    GLuint i = m_indices.size();

    switch (front) {
        case Front::FACING_AXIS:
            m_indices.insert(m_indices.end(), {i, i + 1, i + 2, i + 2, i + 3, i});
            break;
        case Front::AGAINST_AXIS:
            m_indices.insert(m_indices.end(), {i, i + 3, i + 2, i + 2, i + 1, i});
            break;
    }
}
