#include "ChunkMesh.hpp"

void ChunkMesh::addFace(const Face& face,
                        const TextureAtlasCoord& texture,
                        std::uint32_t x, std::uint32_t y, std::uint32_t z)
{
    for (int i = 0; i < 6; ++i) {
        int faceShift = i * 3;
        int texShift = i * 2;
        addVertex({x + face[faceShift], y + face[faceShift + 1], z + face[faceShift + 2]},
                  {texture[texShift], texture[texShift + 1]});
    }
}
