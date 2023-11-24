#ifndef SHADER_LOADER_HPP
#define SHADER_LOADER_HPP

#include <string>

#include <glad/glad.h>

class ShaderLoader {

public:
    ShaderLoader() = delete;
    static GLuint load(const std::string& vertexName, const std::string& fragmentName);

private:
    static GLuint compile(const GLchar* code, GLenum shaderType);
    static GLuint link(GLuint vertex, GLuint fragment);
};

#endif
