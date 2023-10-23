#ifndef BASIC_SHADER_HPP
#define BASIC_SHADER_HPP

#include "Shader.hpp"

class BasicShader : public Shader {

public:
    BasicShader(const std::string& vertexFile = "basic.vert",
                const std::string& fragmentFile = "basic.frag");

protected:
    virtual void getUniforms() override;

private:
    GLuint m_modelMatrixLocation;
    GLuint m_viewMatrixLocation;
    GLuint m_projectionMatrixLocation;
};

#endif
