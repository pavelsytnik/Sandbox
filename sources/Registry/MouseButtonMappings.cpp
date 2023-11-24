#include "MouseButtonMappings.hpp"
#include "../Input/MouseButtonMapping.hpp"

MouseButtonMappings::MouseButtonMappings() :
    BREAK(Registry::registerMouseButton({SDL_BUTTON_LEFT})),
    PUT(Registry::registerMouseButton({SDL_BUTTON_RIGHT})),
    SELECT(Registry::registerMouseButton({SDL_BUTTON_MIDDLE}))
{}
