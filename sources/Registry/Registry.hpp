#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include "../Input/KeyMapping.hpp"

class MouseButtonMapping;

#include <vector>
#include <memory>

class World;

using KeyMappingPointers = std::vector<std::shared_ptr<KeyMapping>>;
using ButtonPointers = std::vector<std::shared_ptr<MouseButtonMapping>>;

class Registry {

public:
    Registry() = delete;

    static std::shared_ptr<KeyMapping> registerKey(const KeyMapping& key);
    static KeyMappingPointers getKeys();

    static std::shared_ptr<MouseButtonMapping> registerMouseButton(const MouseButtonMapping& button);
    static ButtonPointers getMouseButtons();

    static void clear();

private:
    static KeyMappingPointers m_keyMappingsHolder;
    static ButtonPointers m_buttonHolder;
};

#endif
