#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include <memory>
#include <vector>

class KeyMapping;
class MouseButtonMapping;
class Block;

using KeyRegistry = std::vector<std::unique_ptr<KeyMapping>>;
using ButtonRegistry = std::vector<std::unique_ptr<MouseButtonMapping>>;
using BlockRegistry = std::vector<std::unique_ptr<Block>>;

namespace registry {

    KeyMapping& registerKey(const KeyMapping& key);
    KeyRegistry& getKeys();

    MouseButtonMapping& registerButton(const MouseButtonMapping& button);
    ButtonRegistry& getButtons();

    Block& registerBlock(const Block& block);
    BlockRegistry& getBlocks();

    void clear();
}

#endif
