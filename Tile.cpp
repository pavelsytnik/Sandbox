#include "Tile.hpp"

#include <cstring>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ImageLoader.hpp"

Tile::Tile(std::string texturePath) {

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenerateMipmap(GL_TEXTURE_2D);

    image_t image = ImageLoader::loadPNG(texturePath);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);
}

Tile::~Tile() {
    glDeleteTextures(1, &m_textureID);
}

GLuint Tile::textureID() {
    return m_textureID;
}
