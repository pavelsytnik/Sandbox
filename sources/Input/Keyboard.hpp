#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <SDL2/SDL.h>

#include "../Registry/Registry.hpp"

class Keyboard {

public:
    Keyboard();
    void handleInput(const SDL_KeyboardEvent& event);

private:
    KeyRegistry& m_keys;
};

#endif
