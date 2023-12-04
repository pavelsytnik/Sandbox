#include "BlockModel.hpp"

BlockModel::BlockModel(TextureShift texture) :
    m_top(texture),
    m_bottom(texture),
    m_side(texture)
{}

BlockModel::BlockModel(TextureShift top, TextureShift bottom, TextureShift side) :
    m_top(top),
    m_bottom(bottom),
    m_seide(side)
{}

TextureShift BlockModel::getTopTexture() const {
    return m_top;
}

TextureShift BlockModel::getBottomTexture() const {
    return m_bottom;
}

TextureShift BlockModel::getSideTexture() const {
    return m_side;
}
