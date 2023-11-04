#ifndef MOUSE_BUTTON_MAPPINGS_HPP
#define MOUSE_BUTTON_MAPPINGS_HPP

#include "Registry.hpp"
#include "../Input/MouseButtonMapping.hpp"

class MouseButtonMappings {
public:
    MouseButtonMappings(const MouseButtonMappings&) = delete;

    static MouseButtonMappings& getInstance();
    static void deleteInstance();

    const std::shared_ptr<MouseButtonMapping> BREAK;
    const std::shared_ptr<MouseButtonMapping> PUT;
    const std::shared_ptr<MouseButtonMapping> SELECT;

private:
    MouseButtonMappings();

    static MouseButtonMappings* m_instance;
};

#endif
