#include "Keyboard.hpp"
#include "KeyMapping.hpp"

Keyboard::Keyboard() :
    m_keys(Registry::getKeys())
{}

void Keyboard::handleInput(const SDL_KeyboardEvent& event) {
    for (auto& key : m_keys) {
        if (event.keysym.scancode == key->getScancode()) {
            update(*key, event);
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
