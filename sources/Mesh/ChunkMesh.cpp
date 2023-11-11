#include "ChunkMesh.hpp"

void ChunkMesh::addFace(const std::array<GLfloat, 18>& face,
                        const std::array<GLfloat, 12>& texture)
{
    for (int i = 0; i < 6; ++i) {
        int faceShift = i * 3;
        int texShift = i * 2;
        addVertex({face[faceShift], face[faceShift + 1], face[faceShift + 2]},
                  {texture[texShift], texture[texShift + 1]});
    }
}
