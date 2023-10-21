#include "ShaderLoader.hpp"

#include <fstream>
#include <sstream>

GLuint ShaderLoader::load(const std::string& vertexFile, const std::string& fragmentFile) {

    std::ifstream vertFile("resources/shaders/" + vertexFile);
    std::ifstream fragFile("resources/shaders/" + fragmentFile);

    std::stringstream vertStream, fragStream;
    vertStream << vertFile.rdbuf();
    fragStream << fragFile.rdbuf();

    vertFile.close();
    fragFile.close();

    std::string vertexShaderCode = vertStream.str();
    std::string fragmentShaderCode = fragStream.str();


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
