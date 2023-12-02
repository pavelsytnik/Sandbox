#include "MouseButtonMappings.hpp"
#include "Registry.hpp"

MouseButtonMappings::MouseButtonMappings() :
    BREAK(Registry::registerButton({SDL_BUTTON_LEFT})),
    PUT(Registry::registerButton({SDL_BUTTON_RIGHT})),
    SELECT(Registry::registerButton({SDL_BUTTON_MIDDLE}))
{}
