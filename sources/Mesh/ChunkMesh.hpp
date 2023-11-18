#ifndef CHUNK_MESH_HPP
#define CHUNK_MESH_HPP

#include <array>
#include <cstdint>

#include "Mesh.hpp"

using Face = std::array<GLfloat, 12>;
using TextureAtlasCoord = std::array<GLfloat, 8>;

class ChunkMesh : public Mesh {

public:
    ChunkMesh() = default;

    void addFace(const Face& face,
                 const TextureAtlasCoord& texture,
                 std::int32_t x,std::int32_t y, std::int32_t z,
                 GLfloat light);
};

#endif
