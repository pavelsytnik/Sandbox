#include "ChunkMeshBuilder.hpp"
#include "Faces.hpp"

#include "../Texture/BlocksAtlas.hpp"
#include "../Holder/BlockModelHolder.hpp"
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

    auto& models = BlockModelHolder::getInstance();
    //auto texture = atlas.getTexture(0, 0);

    for (auto i = 0; i < CHUNK_VOLUME; ++i) {
        int x = i % CHUNK_SIZE;
        int y = i / CHUNK_AREA;
        int z = (i / CHUNK_SIZE) % CHUNK_SIZE;

        const auto& block = m_section.getBlock({x, y, z});
        BlockID id = block.getID();
        BlockModel* model;

        switch (int(id)) {
            case 1:
                model = &models.stone;
                break;
            case 2:
                model = &models.grass;
                break;
            default:
                model = nullptr;
                break;
        }

        if (block.isAir() || !model)
            continue;

        if (shouldMakeFace({x, y - 1, z}))
            tryAddFace(faces::bottom, BlocksAtlas::getTexture(model->getBottomTexture().x, model->getBottomTexture().y), {x, y, z}, .7f);
        if (shouldMakeFace({x, y + 1, z}))
            tryAddFace(faces::top, BlocksAtlas::getTexture(model->getTopTexture().x, model->getTopTexture().y), {x, y, z}, 1.f);
        if (shouldMakeFace({x - 1, y, z}))
            tryAddFace(faces::left, BlocksAtlas::getTexture(model->getSideTexture().x, model->getSideTexture().y), {x, y, z}, .8f);
        if (shouldMakeFace({x + 1, y, z}))
            tryAddFace(faces::right, BlocksAtlas::getTexture(model->getSideTexture().x, model->getSideTexture().y), {x, y, z}, .8f);
        if (shouldMakeFace({x, y, z - 1}))
            tryAddFace(faces::back, BlocksAtlas::getTexture(model->getSideTexture().x, model->getSideTexture().y), {x, y, z}, .9f);
        if (shouldMakeFace({x, y, z + 1}))
            tryAddFace(faces::front, BlocksAtlas::getTexture(model->getSideTexture().x, model->getSideTexture().y), {x, y, z}, .9f);
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
