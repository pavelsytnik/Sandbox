#ifndef AIR_BLOCK_HPP
#define AIR_BLOCK_HPP

#include "Block.hpp"

class AirBlock : public Block {

public:
    AirBlock(std::uint8_t id);

    bool isAir() const override;
};

#endif
