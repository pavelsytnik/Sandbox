#ifndef CHUNK_MESH_HPP
#define CHUNK_MESH_HPP

#include <array>

#include "Mesh.hpp"
#include "../Texture/Texture.hpp"

class ChunkMesh : public Mesh {

public:
    ChunkMesh() = default;

    void addFace(const std::array<GLfloat, 18>& face, const std::array<GLfloat, 12>& texture);
};

#endif
