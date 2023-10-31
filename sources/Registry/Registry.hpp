#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include "../Input/KeyMapping.hpp"

#include <vector>
#include <memory>

using KeyMappingPointers = std::vector<std::shared_ptr<KeyMapping>>;

class Registry {

public:
    Registry() = delete;
    static std::shared_ptr<KeyMapping> registerKey(const KeyMapping& key);
    static KeyMappingPointers getKeys();
    static void clear();

private:
    static KeyMappingPointers m_keyMappingsHolder;
};

#endif
