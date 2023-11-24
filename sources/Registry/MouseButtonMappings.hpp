#ifndef MOUSE_BUTTON_MAPPINGS_HPP
#define MOUSE_BUTTON_MAPPINGS_HPP

#include "Registry.hpp"
#include "../Input/MouseButtonMapping.hpp"
#include "../Util/Singleton.hpp"

class MouseButtonMappings : public Singleton<MouseButtonMappings> {

    friend class Singleton<MouseButtonMappings>;

public:
    const std::shared_ptr<MouseButtonMapping> BREAK;
    const std::shared_ptr<MouseButtonMapping> PUT;
    const std::shared_ptr<MouseButtonMapping> SELECT;

private:
    MouseButtonMappings();
};

#endif
