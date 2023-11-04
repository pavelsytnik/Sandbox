#include "Registry.hpp"

#include "../Input/MouseButtonMapping.hpp"

KeyMappingPointers Registry::m_keyMappingsHolder;
std::vector<InputListener> Registry::m_inputListenersHolder;
ButtonPointers Registry::m_buttonHolder;

void Registry::clear() {
    //for (auto* key : m_keyMappingsHolder) {
        //delete key;
    //}
    m_keyMappingsHolder.clear();
}

std::shared_ptr<KeyMapping> Registry::registerKey(const KeyMapping& key) {
    auto keyPtr = std::make_shared<KeyMapping>(key);
    m_keyMappingsHolder.push_back(keyPtr);
    return keyPtr;
}

KeyMappingPointers Registry::getKeys() {
    return m_keyMappingsHolder;
}

void Registry::registerListener(InputListener listener) {
    m_inputListenersHolder.push_back(listener);
}

std::vector<InputListener> Registry::getListeners() {
    return m_inputListenersHolder;
}

std::shared_ptr<MouseButtonMapping> Registry::registerMouseButton(const MouseButtonMapping& button) {
    auto btnPtr = std::make_shared<MouseButtonMapping>(button);
    m_buttonHolder.push_back(btnPtr);
    return btnPtr;
}

ButtonPointers Registry::getMouseButtons() {
    return m_buttonHolder;
}
