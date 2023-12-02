#include "Registry.hpp"

#include "../Input/KeyMapping.hpp"
#include "../Input/MouseButtonMapping.hpp"
#include "../Block/Block.hpp"

KeyRegistry Registry::_keyRegistry;
ButtonRegistry Registry::_buttonRegistry;
BlockRegistry Registry::_blockRegistry;

KeyMapping& Registry::registerKey(const KeyMapping& key) {
    _keyRegistry.push_back(std::make_unique<KeyMapping>(key));
    return *_keyRegistry.back();
}

KeyRegistry& Registry::getKeys() {
    return _keyRegistry;
}

MouseButtonMapping& Registry::registerButton(const MouseButtonMapping& button) {
    _buttonRegistry.push_back(std::make_unique<MouseButtonMapping>(button));
    return *_buttonRegistry.back();
}

ButtonRegistry& Registry::getButtons() {
    return _buttonRegistry;
}

BlockRegistry& Registry::getBlocks() {
    return _blockRegistry;
}

void Registry::clear() {
    _keyRegistry.clear();
    _buttonRegistry.clear();
    _blockRegistry.clear();
}
