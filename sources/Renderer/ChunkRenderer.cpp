#include "ChunkRenderer.hpp"
#include "../Camera.hpp"

void ChunkRenderer::add(const std::shared_ptr<ChunkMesh>& mesh)
{
    m_meshes.push_back(mesh);
}

void ChunkRenderer::clear()
{
    m_meshes.clear();
}

void ChunkRenderer::render(const Camera& camera)
{
    m_shader.use();
    m_atlas.bind();

    m_shader.loadModelMatrix(glm::mat4(1.f));
    m_shader.loadViewMatrix(camera.getViewMatrix());
    m_shader.loadProjectionMatrix(camera.getProjectionMatrix());

    for (auto& mesh : m_meshes)
        mesh.lock()->draw();
}
