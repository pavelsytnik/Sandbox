#ifndef CHUNK_RENDERER_HPP
#define CHUNK_RENDERER_HPP

#include <vector>
#include <memory>

#include "../Shader/BasicShader.hpp"
#include "../Mesh/ChunkMesh.hpp"
#include "../Texture/Texture.hpp"
#include "../World/Chunk/Chunk.hpp"

class Camera;

class ChunkRenderer {

public:
    ChunkRenderer();

    //void add(const std::shared_ptr<ChunkMesh>& mesh);
    void add(const Chunk& chunk);
    void clear();
    void render(const Camera& camera);

private:
    BasicShader m_shader;
    std::vector<std::unique_ptr<ChunkMesh>> m_meshes;
    Texture m_atlas;
};

#endif
