#include "ShaderLoader.hpp"

#include <fstream>
#include <sstream>

#include "FileReader.hpp"

GLuint ShaderLoader::load(const std::string& vertexFile, const std::string& fragmentFile) {

    std::string folder("resources/shaders/");
    std::string vertexShaderCode(readEntire(folder + vertexFile));
    std::string fragmentShaderCode(readEntire(folder + fragmentFile));


    GLuint vertexShader = compile(vertexShaderCode.c_str(), GL_VERTEX_SHADER);
    GLuint fragmentShader = compile(fragmentShaderCode.c_str(), GL_FRAGMENT_SHADER);

    GLuint program = link(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    return program;
}

GLuint ShaderLoader::compile(const GLchar* code, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &code, nullptr);
    glCompileShader(shader);

    return shader;
}

GLuint ShaderLoader::link(GLuint vertexShader, GLuint fragmentShader) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    return program;
}
