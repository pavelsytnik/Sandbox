#include "BasicShader.hpp"

#include <glm/gtc/type_ptr.hpp>

#include "UniformLoader.hpp"

BasicShader::BasicShader(const std::string& vertexName,
                         const std::string& fragmentName)
    : Shader(vertexName, fragmentName)
{
    getUniforms();
}

void BasicShader::getUniforms() {
    m_modelMatrixLocation = glGetUniformLocation(m_id, "model");
    m_viewMatrixLocation = glGetUniformLocation(m_id, "view");
    m_projectionMatrixLocation = glGetUniformLocation(m_id, "projection");
}

void BasicShader::loadModelMatrix(const glm::mat4& model) {
    loadMatrix4(m_modelMatrixLocation, model);
}

void BasicShader::loadViewMatrix(const glm::mat4& view) {
    loadMatrix4(m_viewMatrixLocation, view);
}

void BasicShader::loadProjectionMatrix(const glm::mat4& projection) {
    loadMatrix4(m_projectionMatrixLocation, projection);
}
