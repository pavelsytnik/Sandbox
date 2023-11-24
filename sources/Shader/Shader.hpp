#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include <glad/glad.h>

class Shader {

public:
    Shader(const std::string& vertexFile, const std::string& fragmentFile);
    virtual ~Shader();
    void use() const;
    //GLuint getID() const;

protected:
    virtual void getUniforms() = 0;
    GLuint m_id;
};

#endif
