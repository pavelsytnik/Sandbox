#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <array>
#include <cstddef>
#include <cstdint>

#include "../../Block/Block.hpp"
#include "../../Util/ChunkPos.hpp"
#include "../../Util/BlockPos.hpp"

class World;

constexpr std::size_t CHUNK_SIZE = 16;
constexpr std::size_t CHUNK_AREA = CHUNK_SIZE * CHUNK_SIZE;
constexpr std::size_t CHUNK_VOLUME = CHUNK_AREA * CHUNK_SIZE;

constexpr std::uint8_t MAX_CHUNK_HEIGHT = 255;

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
    std::array<BlockID, CHUNK_VOLUME> m_blocks;
};

#endif
