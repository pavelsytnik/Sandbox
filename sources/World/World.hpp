#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
#include <unordered_map>

#include "../Entity/Player.hpp"
#include "Chunk/Chunk.hpp"
#include "../Util/ChunkPos.hpp"
#include "../Util/BlockPos.hpp"

class Block;

class World {

public:
    World(std::int32_t xChunks, std::int32_t zChunks);
    ~World();

    const Block& getBlock(const BlockPos& pos) const;
    void setBlock(const Block& block, const BlockPos& pos);

    void update(float dt);

    Player& getPlayer();

    const std::unordered_map<ChunkPos, Chunk>& getChunks() const;

    //std::uint32_t getXSize() const;
    //std::uint32_t getYSize() const;
    //std::uint32_t getZSize() const;

private:
    //std::uint8_t* m_blocks;
    std::unordered_map<ChunkPos, Chunk> m_chunks;
    //std::uint32_t m_xSize, m_ySize, m_zSize;

    Player m_player;
};

#endif
