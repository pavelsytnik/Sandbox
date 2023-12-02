#ifndef CHUNK_MESH_BUILDER_HPP
#define CHUNK_MESH_BUILDER_HPP

#include <array>
#include <memory>
#include <cstdint>

#include <glad/glad.h>

#include "ChunkMesh.hpp"
#include "../World/Chunk/Chunk.hpp" // temporary. Be replaced by ChunkSection
#include "../Util/BlockPos.hpp"

class ChunkMeshBuilder {

public:
    ChunkMeshBuilder(const Chunk& chunk);

    void create();
    void build();

    std::unique_ptr<ChunkMesh> getResult();

private:
    bool shouldMakeFace(const BlockPos& pos) const;
    void tryAddFace(const Face& face,
                    const TextureAtlasCoord& texture,
                    const BlockPos& pos,
                    GLfloat light);

    std::unique_ptr<ChunkMesh> m_chunkMesh;
    const Chunk& m_chunk;
};

#endif
