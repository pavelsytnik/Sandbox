#include "AirBlock.hpp"

AirBlock::AirBlock(BlockID id) :
    Block(id)
{}

bool AirBlock::isAir() const {
    return true;
}
