#include "ChunkRenderer.hpp"
#include "../Camera.hpp"
#include "../Util/Paths.hpp"
#include "../Mesh/ChunkMeshBuilder.hpp"

#include <iostream>

ChunkRenderer::ChunkRenderer() :
    m_shader(files::chunkVertexShader, files::chunkFragmentShader),
    m_atlas(files::blockAtlas)
{}

void ChunkRenderer::add(const ChunkSection& chunk)
{
    auto mesh = ChunkMeshBuilder(chunk).create().build().getResult();
    mesh->setData();

    m_meshes[glm::ivec3(chunk.getChunkPos().x, chunk.getLevel(), chunk.getChunkPos().z)] = std::move(mesh);
}

void ChunkRenderer::clear()
{
    m_meshes.clear();
}

void ChunkRenderer::render(const Camera& camera)
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glFrontFace(GL_CCW);

    m_shader.use();
    m_atlas.bind();

    m_shader.loadModelMatrix(glm::mat4(1.f));
    m_shader.loadViewMatrix(camera.getViewMatrix());
    m_shader.loadProjectionMatrix(camera.getProjectionMatrix());

    for (auto& mesh : m_meshes)
        mesh.second->draw();
}


