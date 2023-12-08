#include "ChunkMeshBuilder.hpp"
#include "Faces.hpp"

#include "../Texture/BlocksAtlas.hpp"
#include "../Util/Paths.hpp"
#include "../Block/Block.hpp"

ChunkMeshBuilder::ChunkMeshBuilder(const ChunkSection& section) :
    m_section(section)
{
}

ChunkMeshBuilder& ChunkMeshBuilder::create() {
    m_chunkMesh.reset(new ChunkMesh);
    return *this;
}

ChunkMeshBuilder& ChunkMeshBuilder::build() {

    BlocksAtlas atlas(files::blockAtlas);
    auto texture = atlas.getTexture(0, 0);

    for (auto i = 0; i < CHUNK_VOLUME; ++i) {
        int x = i % CHUNK_SIZE;
        int y = i / CHUNK_AREA;
        int z = (i / CHUNK_SIZE) % CHUNK_SIZE;

        if (m_section.getBlock({x, y, z}).isAir())
            continue;

        if (shouldMakeFace({x, y - 1, z}))
            tryAddFace(faces::bottom, texture, {x, y, z}, .7f);
        if (shouldMakeFace({x, y + 1, z}))
            tryAddFace(faces::top, texture, {x, y, z}, 1.f);
        if (shouldMakeFace({x - 1, y, z}))
            tryAddFace(faces::left, texture, {x, y, z}, .8f);
        if (shouldMakeFace({x + 1, y, z}))
            tryAddFace(faces::right, texture, {x, y, z}, .8f);
        if (shouldMakeFace({x, y, z - 1}))
            tryAddFace(faces::back, texture, {x, y, z}, .9f);
        if (shouldMakeFace({x, y, z + 1}))
            tryAddFace(faces::front, texture, {x, y, z}, .9f);
    }

    return *this;
}

std::unique_ptr<ChunkMesh> ChunkMeshBuilder::getResult() {
    return std::move(m_chunkMesh);
}

bool ChunkMeshBuilder::shouldMakeFace(const BlockPos& pos) const {

    return m_section.getBlock(pos).isAir();
}

void ChunkMeshBuilder::tryAddFace(const Face& face,
                                  const TextureAtlasCoord& texture,
                                  const BlockPos& pos,
                                  GLfloat light)
{
    BlockPos globalPos{
        m_section.getChunkPos().x * CHUNK_SIZE + pos.x,
        m_section.getLevel() * CHUNK_SIZE + pos.y,
        m_section.getChunkPos().z * CHUNK_SIZE + pos.z
    };

    m_chunkMesh->addFace(face, texture, globalPos, light);
}
