#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include "../Input/KeyMapping.hpp"

#include <vector>

class Registry {

public:
    ~Registry();
    KeyMapping* registerKey(const KeyMapping& key);

private:
    std::vector<KeyMapping*> m_keyMappingsHolder;
};

#endif
