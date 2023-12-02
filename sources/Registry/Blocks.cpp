#include "Blocks.hpp"
#include "Registry.hpp"

#include "../Block/Block.hpp"
#include "../Block/AirBlock.hpp"

Blocks::Blocks() :
    AIR(Registry::registerBlock(AirBlock(0))),
    STONE(Registry::registerBlock(Block(1))),
    GRASS(Registry::registerBlock(Block(2)))
{}
