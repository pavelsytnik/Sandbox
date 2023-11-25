#include "Registry.hpp"

#include "../Input/KeyMapping.hpp"
#include "../Input/MouseButtonMapping.hpp"
#include "../Block/Block.hpp"

namespace registry {

    namespace {
        KeyRegistry _keyRegistry;
        ButtonRegistry _buttonRegistry;
        BlockRegistry _blockRegistry;
    }

    KeyMapping& registerKey(const KeyMapping& key) {
        _keyRegistry.push_back(std::make_unique<KeyMapping>(key));
        return *_keyRegistry.back();
    }

    KeyRegistry& getKeys() {
        return _keyRegistry;
    }

    MouseButtonMapping& registerButton(const MouseButtonMapping& button) {
        _buttonRegistry.push_back(std::make_unique<MouseButtonMapping>(button));
        return *_buttonRegistry.back();
    }

    ButtonRegistry& getButtons() {
        return _buttonRegistry;
    }

    Block& registerBlock(const Block& block) {
        _blockRegistry.push_back(std::make_unique<Block>(block));
        return *_blockRegistry.back();
    }

    BlockRegistry& getBlocks() {
        return _blockRegistry;
    }

    void clear() {
        _keyRegistry.clear();
        _buttonRegistry.clear();
        _blockRegistry.clear();
    }
}
