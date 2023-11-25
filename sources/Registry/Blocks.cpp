#include "Blocks.hpp"
#include "Registry.hpp"

using namespace registry;

Blocks::Blocks() :
    AIR(registerBlock(Block(0))),
    STONE(registerBlock(Block(1))),
    GRASS(registerBlock(Block(2)))
{}
