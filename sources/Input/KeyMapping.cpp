#include "KeyMapping.hpp"

KeyMapping::KeyMapping(SDL_Scancode scancode) :
    m_scancode(scancode), m_heldDown(false)
{}

bool KeyMapping::heldDown() const {
    return m_heldDown;
}

void KeyMapping::setScancode(SDL_Scancode scancode) {
    m_scancode = scancode;
}

SDL_Scancode KeyMapping::getScancode() const {
    return m_scancode;
}
