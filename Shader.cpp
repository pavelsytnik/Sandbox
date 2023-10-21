#include "Shader.hpp"

#include <fstream>
#include <sstream>

#include "ShaderLoader.hpp"

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile) :
    m_id(ShaderLoader::load(vertexFile, fragmentFile))
{}

Shader::~Shader() {
    glDeleteProgram(m_id);
}

void Shader::use() {
    glUseProgram(m_id);
}

GLuint Shader::getID() {
    return m_id;
}
