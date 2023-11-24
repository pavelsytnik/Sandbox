#ifndef BASIC_SHADER_HPP
#define BASIC_SHADER_HPP

#include <glm/glm.hpp>

#include "Shader.hpp"
#include "../Util/Paths.hpp"

class BasicShader : public Shader {

public:
    BasicShader(const std::string& vertexName = files::basicVertexShader,
                const std::string& fragmentName = files::basicFragmentShader);

    void loadModelMatrix(const glm::mat4& model);
    void loadViewMatrix(const glm::mat4& view);
    void loadProjectionMatrix(const glm::mat4& projection);

protected:
    virtual void getUniforms() override;

private:
    GLuint m_modelMatrixLocation;
    GLuint m_viewMatrixLocation;
    GLuint m_projectionMatrixLocation;
};

#endif
