#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include "../Input/KeyMapping.hpp"
//#include "../Input/MouseButtonMapping.hpp"
class MouseButtonMapping;
//#include "InputListeners.hpp" // redo

#include <vector>
#include <memory>

class World;

using KeyMappingPointers = std::vector<std::shared_ptr<KeyMapping>>;
using ButtonPointers = std::vector<std::shared_ptr<MouseButtonMapping>>;
using InputListener = void (*)(World& world);

class Registry {

public:
    Registry() = delete;
    static std::shared_ptr<KeyMapping> registerKey(const KeyMapping& key);
    static KeyMappingPointers getKeys();
    static void registerListener(InputListener listener);
    static std::vector<InputListener> getListeners();
    static std::shared_ptr<MouseButtonMapping> registerMouseButton(const MouseButtonMapping& button);
    static ButtonPointers getMouseButtons();
    static void clear();

private:
    static KeyMappingPointers m_keyMappingsHolder;
    static std::vector<InputListener> m_inputListenersHolder;
    static ButtonPointers m_buttonHolder;
};

#endif
