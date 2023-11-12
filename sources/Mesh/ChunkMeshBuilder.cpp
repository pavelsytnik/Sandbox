#include "ChunkMeshBuilder.hpp"

void ChunkMeshBuilder::create() {
    m_chunkMesh.reset(new ChunkMesh());
}

void ChunkMeshBuilder::build() {

}

std::shared_ptr<ChunkMesh> ChunkMeshBuilder::getResult() const {
    return m_chunkMesh;
}
