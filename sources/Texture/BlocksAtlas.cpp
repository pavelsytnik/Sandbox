#include "BlocksAtlas.hpp"

namespace {
    constexpr int PIXELS_PER_BLOCK = 16;
    constexpr int ATLAS_WIDTH = 16;
    constexpr int ATLAS_HEIGHT = 16;

    constexpr GLfloat PIXEL_SIZE = 1.f / (ATLAS_WIDTH * PIXELS_PER_BLOCK);
}

BlocksAtlas::BlocksAtlas(const std::string& path) :
    Texture(path)
{}

std::array<GLfloat, 12> BlocksAtlas::getTexture(int x, int y) const {

    GLfloat xMin = x / 16.f;
    GLfloat yMin = 1 - y / 16.f - 1 / 16.f;

    GLfloat xMax = xMin + 1 / 16.f;
    GLfloat yMax = yMin + 1 / 16.f;

    return {xMin, yMin, xMax, yMin, xMin, yMax, xMax, yMax, xMin, yMax, xMax, yMin};
}
