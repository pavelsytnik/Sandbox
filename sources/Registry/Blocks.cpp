#include "Blocks.hpp"
#include "Registry.hpp"

#include "../Block/AirBlock.hpp"

using namespace registry;

Blocks::Blocks() :
    AIR(registerBlock(AirBlock(0))),
    STONE(registerBlock(Block(1))),
    GRASS(registerBlock(Block(2)))
{}
