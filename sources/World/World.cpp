#include "World.hpp"

#include <cmath>

#include "../Registry/Registry.hpp"
#include "../Block/Block.hpp"

World::World(std::int32_t xChunks, std::int32_t zChunks) :
    m_chunks(),
    m_player(*this)
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
    
    ChunkPos chunkPos{int(std::floor(float(pos.x) / CHUNK_SIZE)), int(std::floor(float(pos.z) / CHUNK_SIZE))};
    BlockPos blockPos{pos.x % CHUNK_SIZE, pos.y, pos.z % CHUNK_SIZE};

    return m_chunks.at(chunkPos).getBlock(blockPos);
}

void World::setBlock(const Block& block, const BlockPos& pos) {

    ChunkPos chunkPos{int(std::floor(float(pos.x) / CHUNK_SIZE)), int(std::floor(float(pos.z) / CHUNK_SIZE))};

    int x;
    if (pos.x < 0 && pos.x % CHUNK_SIZE != 0) {
        x = CHUNK_SIZE + (pos.x % CHUNK_SIZE);
    } else {
        x = pos.x % CHUNK_SIZE;
    }
    int z;
    if (pos.z < 0 && pos.z % CHUNK_SIZE != 0) {
        z = CHUNK_SIZE + (pos.z % CHUNK_SIZE);
    } else {
        z = pos.z % CHUNK_SIZE;
    }
    BlockPos blockPos{x, pos.y, z};

    m_chunks.at(chunkPos).setBlock(block, blockPos);
}

void World::update(float dt) {
    m_player.move(dt);
}

Player& World::getPlayer() {
    return m_player;
}

//std::uint32_t World::getXSize() const {
//    return m_xSize;
//}
//
//std::uint32_t World::getYSize() const {
//    return m_ySize;
//}
//
//std::uint32_t World::getZSize() const {
//    return m_zSize;
//}
