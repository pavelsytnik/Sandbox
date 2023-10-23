#include "BasicShader.hpp"

#include <glm/gtc/type_ptr.hpp>

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

void BasicShader::loadModelMatrix(const glm::mat4& model) {
    glUniformMatrix4fv(m_modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(model));
}

void BasicShader::loadViewMatrix(const glm::mat4& view) {
    glUniformMatrix4fv(m_viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(view));
}

void BasicShader::loadProjectionMatrix(const glm::mat4& projection) {
    glUniformMatrix4fv(m_projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projection));
}
