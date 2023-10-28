#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include "../Input/KeyMapping.hpp"

#include <vector>

class Registry {

public:
    Registry() = delete;
    static KeyMapping* registerKey(const KeyMapping& key);
    static std::vector<KeyMapping*> getKeys();
    static void clear();

private:
    static std::vector<KeyMapping*> m_keyMappingsHolder;
};

#endif
