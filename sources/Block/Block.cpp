#include "Block.hpp"

Block::Block(std::uint8_t id) : m_id(id) {}

bool Block::isAir() const {
    return false;
}

std::uint8_t Block::getID() const {
    return m_id;
}
