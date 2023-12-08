#ifndef CHUNK_SECTION_HPP
#define CHUNK_SECTION_HPP

#include <array>

#include "../../Block/Block.hpp"
#include "../../Util/ChunkPos.hpp"
#include "ChunkConstants.hpp"

class World;

struct BlockPos;
struct ChunkPos;

class ChunkSection {

public:
    ChunkSection(World* world, const ChunkPos& pos, int level);

    const Block& getBlock(const BlockPos& pos) const;
    void setBlock(const Block& block, const BlockPos& pos);
    ChunkPos getChunkPos() const;
    int getLevel() const;

private:
    static int toArrayIndex(const BlockPos& pos);
    static bool isOutOfBounds(const BlockPos& pos);

    BlockPos toWorldPosition(const BlockPos& blockPos) const;

    World* m_world;
    ChunkPos m_chunkPos;
    int m_level;

    std::array<BlockID, CHUNK_VOLUME> m_blocks;
};

#endif
