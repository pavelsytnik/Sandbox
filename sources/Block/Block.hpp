#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>

using BlockID = std::uint8_t;

class Block {

public:
    Block(BlockID id);

    //virtual bool isOpaque();
    //virtual bool isFullCube();
    virtual bool isAir() const;

    BlockID getID() const;

private:
    BlockID m_id;
};

#endif
