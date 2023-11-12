#ifndef CHUNK_MESH_BUILDER_HPP
#define CHUNK_MESH_BUILDER_HPP

#include <memory>

#include "ChunkMesh.hpp"

class ChunkMeshBuilder {

public:
    ChunkMeshBuilder() = default;
    void create();
    void build();
    std::shared_ptr<ChunkMesh> getResult() const;

private:
    std::shared_ptr<ChunkMesh> m_chunkMesh;
};

#endif
