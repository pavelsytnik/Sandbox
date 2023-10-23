#include "BasicShader.hpp"

BasicShader::BasicShader(const std::string& vertexFile,
                         const std::string& fragmentFile)
    : Shader(vertexFile, fragmentFile)
{
    getUniforms();
}

void BasicShader::getUniforms() {
    m_modelMatrixLocation = glGetUniformLocation(m_id, "model");
    m_viewMatrixLocation = glGetUniformLocation(m_id, "view");
    m_projectionMatrixLocation = glGetUniformLocation(m_id, "projection");
}
