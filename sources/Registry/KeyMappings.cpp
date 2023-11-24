#include "KeyMappings.hpp"
#include "Registry.hpp"

KeyMappings::KeyMappings() :
    FORWARD(Registry::registerKey({SDL_SCANCODE_W})),
    BACKWARD(Registry::registerKey({SDL_SCANCODE_S})),
    LEFT(Registry::registerKey({SDL_SCANCODE_A})),
    RIGHT(Registry::registerKey({SDL_SCANCODE_D})),
    UP(Registry::registerKey({SDL_SCANCODE_SPACE})),
    DOWN(Registry::registerKey({SDL_SCANCODE_LSHIFT}))
{}
