#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "KeyMapping.hpp"

#include "SDL2/SDL.h"

#include <vector>

class Keyboard {

public:
    Keyboard();
    void handleInput(const SDL_KeyboardEvent& event);

private:
    std::vector<KeyMapping*> m_keyMappings;
};

#endif
