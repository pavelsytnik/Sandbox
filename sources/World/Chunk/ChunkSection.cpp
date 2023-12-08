#include "ChunkSection.hpp"

#include "../World.hpp"
#include "../../Block/Block.hpp"
#include "../../Util/BlockPos.hpp"
#include "../../Util/ChunkPos.hpp"
#include "../../Registry/Registry.hpp"

ChunkSection::ChunkSection(World* world, const ChunkPos& pos, int level) :
    m_world(world),
    m_chunkPos(pos),
    m_level(level) {

}

const Block& ChunkSection::getBlock(const BlockPos& pos) const {

    if (isOutOfBounds(pos)) {
        return m_world->getBlock(toWorldPosition(pos));
    }

    auto id = m_blocks[toArrayIndex(pos)];

    // unsafe
    return *Registry::getBlocks()[id];
    // unsafe
}

void ChunkSection::setBlock(const Block& block, const BlockPos& pos) {
    m_blocks[toArrayIndex(pos)] = block.getID();
}

int ChunkSection::toArrayIndex(const BlockPos& pos) {
    return CHUNK_SIZE * (pos.y * CHUNK_SIZE + pos.x) + pos.z;
}

BlockPos ChunkSection::toWorldPosition(const BlockPos& blockPos) const {
    return {
        m_chunkPos.x * CHUNK_SIZE + blockPos.x,
        m_level * CHUNK_SIZE + blockPos.y,
        m_chunkPos.z * CHUNK_SIZE + blockPos.z
    };
}

bool ChunkSection::isOutOfBounds(const BlockPos& pos) {
    return pos.x < 0 || pos.x >= CHUNK_SIZE ||
           pos.y < 0 || pos.y >= CHUNK_SIZE ||
           pos.z < 0 || pos.z >= CHUNK_SIZE;
}

int ChunkSection::getLevel() const {
    return m_level;
}
