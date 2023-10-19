#include "Tessellator.hpp"

#include <iostream>

Tessellator::Tessellator() {
    m_vao.bind();
    m_vbo.bind();

    m_vbo.attachAttributePointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    m_vbo.attachAttributePointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    m_vbo.unbind();
    m_vao.unbind();
}

void Tessellator::addVertex(GLfloat x, GLfloat y, GLfloat z) {
    m_vertices.insert(m_vertices.end(), { x, y, z });
}

void Tessellator::addTextureCoordinate(GLfloat u, GLfloat v) {
    m_vertices.insert(m_vertices.end(), { u, v });
}

std::size_t Tessellator::getBufferSize() {
    return m_vertices.size();
}

void Tessellator::flush() {
    m_vbo.bind();
    m_vbo.setData(m_vertices.size() * sizeof(GLfloat), m_vertices.data(), GL_DYNAMIC_DRAW);
    m_vbo.unbind();

    m_shader.use();

    m_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
    m_vao.unbind();

    clear();
}

void Tessellator::clear() {
    m_vertices.clear();

    m_vao.bind();
    m_vbo.bind();

    m_vbo.setData(0, nullptr, GL_DYNAMIC_DRAW);

    m_vbo.unbind();
    m_vao.unbind();
}

GLuint Tessellator::vbo() {
    return m_vbo.id();
}

GLuint Tessellator::vao() {
    return m_vao.id();
}
