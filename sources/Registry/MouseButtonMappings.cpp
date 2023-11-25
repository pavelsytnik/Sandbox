#include "MouseButtonMappings.hpp"
#include "Registry.hpp"

using namespace registry;

MouseButtonMappings::MouseButtonMappings() :
    BREAK(registerButton({SDL_BUTTON_LEFT})),
    PUT(registerButton({SDL_BUTTON_RIGHT})),
    SELECT(registerButton({SDL_BUTTON_MIDDLE}))
{}
