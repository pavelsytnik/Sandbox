#include "Shader.hpp"

#include <fstream>
#include <sstream>

#include "ShaderLoader.hpp"

Shader::Shader(const std::string& vertexName, const std::string& fragmentName) :
    m_id(ShaderLoader::load(vertexName, fragmentName))
{}

Shader::~Shader() {
    glDeleteProgram(m_id);
}

void Shader::use() const {
    glUseProgram(m_id);
}

//GLuint Shader::getID() const {
//    return m_id;
//}
