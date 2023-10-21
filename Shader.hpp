#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include "glad/glad.h"

class Shader {

public:
    Shader(const std::string& vertexFile, const std::string& fragmentFile);
    ~Shader();
    void use();
    GLuint getID();

private:
    GLuint m_id;
};

#endif
