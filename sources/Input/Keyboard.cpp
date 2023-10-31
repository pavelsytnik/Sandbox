#include "Keyboard.hpp"

#include "../Registry/Registry.hpp"

#include <iostream>

Keyboard::Keyboard() {
    m_keyMappings = Registry::getKeys();
}

void Keyboard::handleInput(const SDL_KeyboardEvent& event) {
    for (auto key : m_keyMappings) {
        if (event.keysym.scancode == key->getScancode()) {
            update(*key, event);
            std::cout << key->getScancode() << std::endl;
            break;
        }
    }
}

void update(KeyMapping& key, const SDL_KeyboardEvent& event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            key.m_heldDown = true;
            break;
        case SDL_KEYUP:
            key.m_heldDown = false;
            break;
    }
}
