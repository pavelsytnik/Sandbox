#include "AirBlock.hpp"

AirBlock::AirBlock(std::uint8_t id) :
    Block(id)
{}

bool AirBlock::isAir() const {
    return true;
}
