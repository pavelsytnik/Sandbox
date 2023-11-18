#include "ChunkMeshBuilder.hpp"
#include "Faces.hpp"

#include "../Texture/BlocksAtlas.hpp"
#include "../Util/Paths.hpp"

ChunkMeshBuilder::ChunkMeshBuilder(const World& world) :
    world(world)
{
}

void ChunkMeshBuilder::create() {
    m_chunkMesh.reset(new ChunkMesh());
}

void ChunkMeshBuilder::build() {
    //std::array<GLfloat, 12> texture{
    //    0, 15 / 16.f,
    //    1 / 16.f, 15 / 16.f,
    //    0, 1,
    //    1 / 16.f, 15 / 16.f,
    //    1 / 16.f, 1,
    //    0, 1};
    //std::array<GLfloat, 12> texture{
    //    0, 15/16.f,
    //    1/16.f, 15/16.f,
    //    0, 1,
    //    0, 1,
    //    1/16.f, 1,
    //    1/16.f, 15/16.f
    //};
    BlocksAtlas atlas(files::blockAtlas);
    auto texture = atlas.getTexture(0, 0);
    for (int x = 0; x < world.getXSize(); ++x) {
        for (int y = 0; y < world.getYSize(); ++y) {
            for (int z = 0; z < world.getZSize(); ++z) {
                if (world.getBlock(x, y, z) == 0) continue;
                if (shouldMakeFace(x, y - 1, z))
                    tryAddFace(faces::bottom, texture, x, y, z, .7f);
                if (shouldMakeFace(x, y + 1, z))
                    tryAddFace(faces::top, texture, x, y, z, 1.f);
                if (shouldMakeFace(x - 1, y, z))
                    tryAddFace(faces::left, texture, x, y, z, .8f);
                if (shouldMakeFace(x + 1, y, z))
                    tryAddFace(faces::right, texture, x, y, z, .8f);
                if (shouldMakeFace(x, y, z - 1))
                    tryAddFace(faces::back, texture, x, y, z, .9f);
                if (shouldMakeFace(x, y, z + 1))
                    tryAddFace(faces::front, texture, x, y, z, .9f);
            }
        }
    }
}

std::shared_ptr<ChunkMesh> ChunkMeshBuilder::getResult() const {
    return m_chunkMesh;
}

bool ChunkMeshBuilder::shouldMakeFace(std::int32_t x, std::int32_t y, std::int32_t z) const {
    return x < 0 || x >= world.getXSize()
        || y < 0 || y >= world.getYSize()
        || z < 0 || z >= world.getZSize()
        || world.getBlock(x, y, z) == 0;
}

void ChunkMeshBuilder::tryAddFace(const Face& face,
                                  const TextureAtlasCoord& texture,
                                  std::int32_t x,
                                  std::int32_t y,
                                  std::int32_t z,
                                  GLfloat light)
{
    //if (shouldMakeFace(x, y, z)) {
    m_chunkMesh->addFace(face, texture, x, y, z, light);
    //}
}
