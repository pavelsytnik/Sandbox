#include "MouseButtonMapping.hpp"

MouseButtonMapping::MouseButtonMapping(Uint8 button) :
    m_heldDown(false),
    m_button(button)
{}

bool MouseButtonMapping::heldDown() const {
    return m_heldDown;
}

Uint8 MouseButtonMapping::getButton() const {
    return m_button;
}

void MouseButtonMapping::setButton(Uint8 button) {
    m_button = button;
}
