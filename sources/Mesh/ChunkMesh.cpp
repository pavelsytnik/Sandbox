#include "ChunkMesh.hpp"

void ChunkMesh::addFace(const Face& face,
                        const TextureAtlasCoord& texture,
                        const BlockPos& pos,
                        GLfloat light)
{
    for (int i = 0; i < 4; ++i) {
        int faceShift = i * 3;
        int texShift = i * 2;
        addVertex({pos.x + face[faceShift], pos.y + face[faceShift + 1], pos.z + face[faceShift + 2]},
                  {texture[texShift], texture[texShift + 1]}, light);
    }

    addIndices();
}
