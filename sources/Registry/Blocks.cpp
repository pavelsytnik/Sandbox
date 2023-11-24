#include "Blocks.hpp"
#include "Registry.hpp"

Blocks::Blocks() :
    AIR(Registry::registerBlock(Block(0))),
    STONE(Registry::registerBlock(Block(1))),
    GRASS(Registry::registerBlock(Block(2)))
{}
