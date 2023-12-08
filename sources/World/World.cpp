#include "World.hpp"

#include <cmath>

#include "../Registry/Registry.hpp"
#include "../Block/Block.hpp"

namespace {
    std::int32_t localAxisPosFrom(std::int32_t n) {
        n %= CHUNK_SIZE;
        return n >= 0 ? n : n + CHUNK_SIZE;
    }

    BlockPos chunkLocalPosFrom(BlockPos globalPos) {
        std::int32_t x = localAxisPosFrom(globalPos.x);
        std::int32_t z = localAxisPosFrom(globalPos.z);

        return {x, globalPos.y, z};
    }
}

World::World(std::int32_t xChunks, std::int32_t zChunks) :
    m_chunks(),
    m_player(*this),
    m_xBorder(xChunks * CHUNK_SIZE),
    m_zBorder(zChunks * CHUNK_SIZE)
{
    for (auto x = -xChunks; x < xChunks; ++x) {
        for (auto z = -zChunks; z < zChunks; ++z) {
            ChunkPos chunkPos{x, z};
            m_chunks.emplace(std::make_pair(std::move(chunkPos), Chunk{this, chunkPos}));
            //setBlock(Registry::getBlocks()[2]->getID(), {x * int(CHUNK_SIZE), 0, z * int(CHUNK_SIZE)});
        }
    }

    for (int y = 0; y < CHUNK_HEIGHT; y++) {
        for (int x = -xChunks * CHUNK_SIZE; x < xChunks * CHUNK_SIZE; x++) {
            for (int z = -zChunks * CHUNK_SIZE; z < zChunks * CHUNK_SIZE; z++) {
                setBlock(Registry::getBlocks()[2]->getID(), {x, y, z});
            }
        }
    }
    //m_player.m_position = glm::vec3(getXSize() / 2, getYSize() + 2, getZSize() / 2);
}

World::~World() {
}

const std::unordered_map<ChunkPos, Chunk>& World::getChunks() const {
    return m_chunks;
}

const Block& World::getBlock(const BlockPos& pos) const {

    // redo
    if (pos.x < -m_xBorder || pos.x >= m_xBorder ||
        pos.y < 0 || pos.y >= CHUNK_HEIGHT ||
        pos.z < -m_zBorder || pos.z >= m_zBorder)
    {
        return *Registry::getBlocks()[0];
    }
    // redo
    
    ChunkPos chunkPos{int(std::floor(float(pos.x) / CHUNK_SIZE)), int(std::floor(float(pos.z) / CHUNK_SIZE))};
    BlockPos blockPos{chunkLocalPosFrom(pos)};

    return m_chunks.at(chunkPos).getBlock(blockPos);
}

void World::setBlock(const Block& block, const BlockPos& pos) {

    ChunkPos chunkPos{int(std::floor(float(pos.x) / CHUNK_SIZE)), int(std::floor(float(pos.z) / CHUNK_SIZE))};
    BlockPos blockPos{chunkLocalPosFrom(pos)};

    m_chunks.at(chunkPos).setBlock(block, blockPos);
}

void World::update(float dt) {
    m_player.move(dt);
}

Player& World::getPlayer() {
    return m_player;
}
