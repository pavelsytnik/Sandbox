#ifndef BLOCKS_ATLAS_HPP
#define BLOCKS_ATLAS_HPP

#include <array>
#include <string>

#include <glad/glad.h>

#include "Texture.hpp"

class BlocksAtlas : public Texture {
    
public:
    BlocksAtlas(const std::string& path);

    static std::array<GLfloat, 8> getTexture(int x, int y);
};

#endif
