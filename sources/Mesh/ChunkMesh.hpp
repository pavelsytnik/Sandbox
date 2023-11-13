#ifndef CHUNK_MESH_HPP
#define CHUNK_MESH_HPP

#include <array>

#include "Mesh.hpp"
#include "../Texture/Texture.hpp"

using Face = std::array<GLfloat, 18>;
using TextureAtlasCoord = std::array<GLfloat, 12>;

class ChunkMesh : public Mesh {

public:
    ChunkMesh() = default;

    void addFace(const Face& face,
                 const TextureAtlasCoord& texture,
                 std::int32_t x,std::int32_t y, std::int32_t z);
};

#endif
