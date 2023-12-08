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

private:
    std::unordered_map<ChunkPos, Chunk> m_chunks;

    Player m_player;

    int m_xBorder, m_zBorder;
};

#endif
