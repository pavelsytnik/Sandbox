#include "ChunkMeshBuilder.hpp"

ChunkMeshBuilder::ChunkMeshBuilder(const World& world) :
    world(world)
{}

void ChunkMeshBuilder::create() {
    m_chunkMesh.reset(new ChunkMesh());
}

void ChunkMeshBuilder::build() {

}

std::shared_ptr<ChunkMesh> ChunkMeshBuilder::getResult() const {
    return m_chunkMesh;
}

bool ChunkMeshBuilder::shouldMakeFace(std::uint32_t x, std::uint32_t y, std::uint32_t z) const {
    return world.getBlock(x, y, z) == 0;
}

void ChunkMeshBuilder::tryAddFace(const Face& face,
                                  const TextureAtlasCoord& texture,
                                  std::uint32_t x,
                                  std::uint32_t y,
                                  std::uint32_t z)
{
    if (shouldMakeFace(x, y, z)) {
        m_chunkMesh->addFace(face, texture, x, y, z);
    }
}
