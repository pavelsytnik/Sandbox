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

class Registry {

public:
    static KeyMapping& registerKey(const KeyMapping& key);
    static KeyRegistry& getKeys();

    static MouseButtonMapping& registerButton(const MouseButtonMapping& button);
    static ButtonRegistry& getButtons();

    template<typename TBlock>
    static TBlock& registerBlock(const TBlock& block);
    static BlockRegistry& getBlocks();

    static void sortBlockRegistry(); // temp
    static void clear();

private:
    static KeyRegistry _keyRegistry;
    static ButtonRegistry _buttonRegistry;
    static BlockRegistry _blockRegistry;
};

#include "Registry.inl"

#endif
