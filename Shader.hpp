#ifndef SHADER_HPP
#define SHADER_HPP

#include "glad/glad.h"

class Shader {
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~Shader();
    void use();
    GLuint id();
private:
    GLuint m_id;
};

#endif
