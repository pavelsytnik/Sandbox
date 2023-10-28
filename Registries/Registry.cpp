#include "Registry.hpp"

std::vector<KeyMapping*> Registry::m_keyMappingsHolder;

void Registry::clear() {
    for (auto* key : m_keyMappingsHolder) {
        delete key;
    }
    m_keyMappingsHolder.clear();
}

KeyMapping* Registry::registerKey(const KeyMapping& key) {
    auto keyPtr = new KeyMapping(key.getScancode());
    m_keyMappingsHolder.push_back(keyPtr);
    return keyPtr;
}

std::vector<KeyMapping*> Registry::getKeys() {
    return m_keyMappingsHolder;
}
