#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <vector>

#include <SDL2/SDL.h>

#include "../Registry/Registry.hpp"

class Keyboard {

public:
    Keyboard();
    void handleInput(const SDL_KeyboardEvent& event);

private:
    KeyMappingPointers m_keyMappings;
};

#endif
