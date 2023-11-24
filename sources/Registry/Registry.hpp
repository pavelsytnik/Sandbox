#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include "../Input/KeyMapping.hpp"

class MouseButtonMapping;
class Block;

#include <vector>
#include <memory>

class World;

using KeyMappingPointers = std::vector<std::shared_ptr<KeyMapping>>;
using ButtonPointers = std::vector<std::shared_ptr<MouseButtonMapping>>;
using BlockPointers = std::vector<std::shared_ptr<Block>>;

class Registry {

public:
    Registry() = delete;

    static std::shared_ptr<KeyMapping> registerKey(const KeyMapping& key);
    static KeyMappingPointers getKeys();

    static std::shared_ptr<MouseButtonMapping> registerMouseButton(const MouseButtonMapping& button);
    static ButtonPointers getMouseButtons();

    static std::shared_ptr<Block> registerBlock(const Block& block);
    static BlockPointers getBlocks();

    static void clear();

private:
    static KeyMappingPointers m_keyMappingsHolder;
    static ButtonPointers m_buttonHolder;
    static BlockPointers m_blockHolder;
};

#endif
