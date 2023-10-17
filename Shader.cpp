#include "Shader.hpp"

#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath) {

    std::ifstream vertFile(vertexShaderPath);
    std::ifstream fragFile(fragmentShaderPath);

    std::stringstream vertStream, fragStream;
    vertStream << vertFile.rdbuf();
    fragStream << fragFile.rdbuf();

    vertFile.close();
    fragFile.close();

    std::string vertString = vertStream.str();
    std::string fragString = fragStream.str();

    const GLchar* vertexShaderCode = vertString.c_str();
    const GLchar* fragmentShaderCode = fragString.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
    glCompileShader(fragmentShader);

    m_id = glCreateProgram();
    glAttachShader(m_id, vertexShader);
    glAttachShader(m_id, fragmentShader);
    glLinkProgram(m_id);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {
    glDeleteShader(m_id);
}

void Shader::use() {
    glUseProgram(m_id);
}

GLuint Shader::id() {
    return m_id;
}
