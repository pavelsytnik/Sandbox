#ifndef BASIC_SHADER_HPP
#define BASIC_SHADER_HPP

#include "Shader.hpp"

#include <glm/glm.hpp>
//#include <glm/gtc/type_ptr.hpp>

class BasicShader : public Shader {

public:
    BasicShader(const std::string& vertexFile = "basic.vert",
                const std::string& fragmentFile = "basic.frag");

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
