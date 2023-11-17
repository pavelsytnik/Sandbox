#include "ChunkMesh.hpp"

void ChunkMesh::addFace(const Face& face,
                        Front facing,
                        const TextureAtlasCoord& texture,
                        std::int32_t x, std::int32_t y, std::int32_t z)
{
    for (int i = 0; i < 4; ++i) {
        int faceShift = i * 3;
        int texShift = i * 2;
        addVertex({x + face[faceShift], y + face[faceShift + 1], z + face[faceShift + 2]},
                  {texture[texShift], texture[texShift + 1]});
    }

    addIndices(facing);
}
