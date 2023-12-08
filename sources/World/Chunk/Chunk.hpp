#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <array>
#include <cstddef>
#include <cstdint>

#include "../../Block/Block.hpp"
#include "../../Util/ChunkPos.hpp"
#include "../../Util/BlockPos.hpp"
#include "ChunkConstants.hpp"
#include "ChunkSection.hpp"

class World;

class Chunk {

public:
    Chunk(World* world, const ChunkPos& pos);
    Chunk() = delete;

    const Block& getBlock(const BlockPos& pos) const;
    void setBlock(const Block& block, const BlockPos& pos);
    const ChunkPos& getPosition() const;

private:
    World* m_world;
    ChunkPos m_pos;

    std::vector<ChunkSection> m_sections; // rewrite to array in future
};

#endif
