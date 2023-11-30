#include "Block.hpp"

Block::Block(BlockID id) : m_id(id) {}

bool Block::isAir() const {
    return false;
}

BlockID Block::getID() const {
    return m_id;
}
