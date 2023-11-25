#include "KeyMappings.hpp"
#include "Registry.hpp"

using namespace registry;

KeyMappings::KeyMappings() :
    FORWARD(registerKey({SDL_SCANCODE_W})),
    BACKWARD(registerKey({SDL_SCANCODE_S})),
    LEFT(registerKey({SDL_SCANCODE_A})),
    RIGHT(registerKey({SDL_SCANCODE_D})),
    UP(registerKey({SDL_SCANCODE_SPACE})),
    DOWN(registerKey({SDL_SCANCODE_LSHIFT}))
{}
