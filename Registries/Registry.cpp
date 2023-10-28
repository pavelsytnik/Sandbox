#include "Registry.hpp"

Registry::~Registry() {
    for (auto* key : m_keyMappingsHolder) {
        delete key;
    }
}

KeyMapping* Registry::registerKey(const KeyMapping& key) {
    auto keyPtr = new KeyMapping(key.getScancode());
    m_keyMappingsHolder.push_back(keyPtr);
    return keyPtr;
}
