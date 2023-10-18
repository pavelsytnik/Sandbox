#ifndef TILE_HPP
#define TILE_HPP

#include <string>

#include "glad/glad.h"

class Tile {
public:
    Tile(std::string texturePath);
    Tile(const Tile&) = delete;
    ~Tile();
    GLuint textureID();
private:
    GLuint m_textureID;
};

#endif
