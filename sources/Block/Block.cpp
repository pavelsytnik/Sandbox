#include "Block.hpp"

Block::Block(std::uint8_t id) : m_id(id) {}

std::uint8_t Block::getID() const {
    return m_id;
}
