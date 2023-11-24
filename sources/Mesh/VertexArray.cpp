#include "VertexArray.hpp"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_id);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_id);
}

//GLuint VertexArray::getID() {
//    return m_id;
//}

void VertexArray::bind() {
    glBindVertexArray(m_id);
}

//void VertexArray::unbind() {
//    glBindVertexArray(0);
//}
