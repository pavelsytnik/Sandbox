#ifndef CHUNK_RENDERER_HPP
#define CHUNK_RENDERER_HPP

#include <vector>
#include <memory>

#include "../Shader/BasicShader.hpp"
#include "../Mesh/ChunkMesh.hpp"
#include "../Texture/Texture.hpp"

class Camera;

class ChunkRenderer {

public:
    void add(const std::shared_ptr<ChunkMesh>& mesh);
    void clear();
    void render(const Camera& camera);

private:
    BasicShader m_shader;
    std::vector<std::weak_ptr<ChunkMesh>> m_meshes; // Possibly bad idea
    Texture m_atlas;
};

#endif
