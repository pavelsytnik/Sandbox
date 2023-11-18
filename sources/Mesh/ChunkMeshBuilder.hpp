#ifndef CHUNK_MESH_BUILDER_HPP
#define CHUNK_MESH_BUILDER_HPP

#include <array>
#include <memory>
#include <cstdint>

#include <glad/glad.h>

#include "ChunkMesh.hpp"
#include "../World/World.hpp" // temporary. Be replaced by Chunk

class ChunkMeshBuilder {

public:
    ChunkMeshBuilder(const World& world);

    void create();
    void build();

    std::shared_ptr<ChunkMesh> getResult() const;

private:
    bool shouldMakeFace(std::int32_t x, std::int32_t y, std::int32_t z) const;
    void tryAddFace(const Face& face,
                    const TextureAtlasCoord& texture,
                    std::int32_t x,
                    std::int32_t y,
                    std::int32_t z);

    std::shared_ptr<ChunkMesh> m_chunkMesh;
    const World& world;
};

#endif
