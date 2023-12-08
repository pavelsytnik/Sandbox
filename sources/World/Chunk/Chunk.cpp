#include "Chunk.hpp"
#include "../../Registry/Registry.hpp"

Chunk::Chunk(World* world, const ChunkPos& pos) :
    m_world(world),
    m_pos(pos)
{
    for (int i = 0; i < CHUNK_SECTION_COUNT; i++) {
        m_sections.push_back({m_world, m_pos, i});
    }
}

const Block& Chunk::getBlock(const BlockPos& pos) const {

    int level = pos.y / CHUNK_SIZE;
    int sectionY = pos.y % CHUNK_SIZE;

    return m_sections[level].getBlock({pos.x, sectionY, pos.z});
}

void Chunk::setBlock(const Block& block, const BlockPos& pos) {
    
    int level = pos.y / CHUNK_SIZE;
    int sectionY = pos.y % CHUNK_SIZE;

    m_sections[level].setBlock(block, {pos.x, sectionY, pos.z});
}

const ChunkPos& Chunk::getPosition() const {
    return m_pos;
}
