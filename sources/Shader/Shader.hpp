#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include <glad/glad.h>

class Shader {

public:
    Shader(const std::string& vertexName, const std::string& fragmentName);
    virtual ~Shader();
    void use() const;
    //GLuint getID() const;

protected:
    virtual void getUniforms() = 0;
    GLuint m_id;
};

#endif
