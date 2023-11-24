#include "Registry.hpp"

#include "../Input/MouseButtonMapping.hpp"
#include "../Block/Block.hpp"

KeyMappingPointers Registry::m_keyMappingsHolder;
ButtonPointers Registry::m_buttonHolder;
BlockPointers Registry::m_blockHolder;

void Registry::clear() {
    m_keyMappingsHolder.clear();
    m_buttonHolder.clear();
    m_blockHolder.clear();
}

std::shared_ptr<KeyMapping> Registry::registerKey(const KeyMapping& key) {
    auto keyPtr = std::make_shared<KeyMapping>(key);
    m_keyMappingsHolder.push_back(keyPtr);
    return keyPtr;
}

KeyMappingPointers Registry::getKeys() {
    return m_keyMappingsHolder;
}

std::shared_ptr<MouseButtonMapping> Registry::registerMouseButton(const MouseButtonMapping& button) {
    auto btnPtr = std::make_shared<MouseButtonMapping>(button);
    m_buttonHolder.push_back(btnPtr);
    return btnPtr;
}

ButtonPointers Registry::getMouseButtons() {
    return m_buttonHolder;
}

std::shared_ptr<Block> Registry::registerBlock(const Block& block) {
    auto blockPtr = std::make_shared<Block>(block);
    m_blockHolder.push_back(blockPtr);
    return blockPtr;
}

BlockPointers Registry::getBlocks() {
    return m_blockHolder;
}
