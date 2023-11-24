#include "BlocksAtlas.hpp"

namespace {
    constexpr int ATLAS_SIDE_LENGTH = 256;
    constexpr int TEXTURE_SIDE_LENGTH = 16;

    constexpr GLfloat TEXTURE_PORTION = (GLfloat)TEXTURE_SIDE_LENGTH / ATLAS_SIDE_LENGTH;
}

BlocksAtlas::BlocksAtlas(const std::string& path) :
    Texture(path)
{}

std::array<GLfloat, 8> BlocksAtlas::getTexture(int x, int y) const {

    GLfloat xMin = x * TEXTURE_PORTION;
    GLfloat yMin = 1 - y * TEXTURE_PORTION - TEXTURE_PORTION;

    GLfloat xMax = xMin + TEXTURE_PORTION;
    GLfloat yMax = yMin + TEXTURE_PORTION;

    return {xMax, yMin, xMax, yMax, xMin, yMax, xMin, yMin};
}
