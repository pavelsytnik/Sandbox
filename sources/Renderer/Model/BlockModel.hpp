#ifndef BLOCK_MODEL_HPP
#define BLOCK_MODEL_HPP

struct TextureShift {
    int x, y;
};

class BlockModel {

public:
    BlockModel(TextureShift texture);
    BlockModel(TextureShift top, TextureShift bottom, TextureShift side);

    TextureShift getTopTexture() const;
    TextureShift getBottomTexture() const;
    TextureShift getSideTexture() const;

private:
    TextureShift m_top;
    TextureShift m_bottom;
    TextureShift m_side;
};

#endif
