#include "Chunk.hpp"
#include "../../Registry/Registry.hpp"

Chunk::Chunk(World* world, const ChunkPos& pos) :
    m_world(world),
    m_pos(pos),
    m_blocks()
{}

const Block& Chunk::getBlock(const BlockPos& pos) const {

    auto id = m_blocks[CHUNK_SIZE * (pos.y * CHUNK_SIZE + pos.x) + pos.z];

    for (const auto& block : Registry::getBlocks()) {
        if (block->getID() == id) {
            return *block;
        }
    }

    throw 666;
}

void Chunk::setBlock(const Block& block, const BlockPos& pos) {
    m_blocks[CHUNK_SIZE * (pos.y * CHUNK_SIZE + pos.x) + pos.z] = block.getID();
}

const ChunkPos& Chunk::getPosition() const {
    return m_pos;
}
