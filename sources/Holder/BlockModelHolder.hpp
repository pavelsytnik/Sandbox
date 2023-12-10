#ifndef BLOCK_MODEL_HOLDER_HPP
#define BLOCK_MODEL_HOLDER_HPP

#include "../Util/Singleton.hpp"
#include "../Renderer/Model/BlockModel.hpp"

// This is a temporary class to hold the block models for rendering
// The special registry is necessary for the purpose

class BlockModelHolder : public Singleton<BlockModelHolder> {

    friend class Singleton<BlockModelHolder>;

public:
    BlockModel stone;
    BlockModel grass;

private:
    BlockModelHolder();
};

#endif
