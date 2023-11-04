#include "Mouse.hpp"

#include "../Registry/MouseButtonMappings.hpp"
#include "MouseButtonMapping.hpp"

Mouse::Mouse() {
    MouseButtonMappings::getInstance();
    m_buttons = Registry::getMouseButtons();
}

void Mouse::handleEvent(const SDL_MouseButtonEvent& event) {
    for (auto& btn : m_buttons) {
        if (event.button == btn->getButton()) {
            update(*btn, event);
        }
    }
}

void Mouse::handleEvent(const SDL_MouseMotionEvent& event) {
    m_dx += event.xrel;
    m_dy += event.yrel;
}

void Mouse::update(MouseButtonMapping& button, const SDL_MouseButtonEvent& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        button.m_heldDown = true;
    } else if (event.type == SDL_MOUSEBUTTONUP) {
        button.m_heldDown = false;
    }
}

Sint32 Mouse::getDX() const {
    auto dx = m_dx;
    m_dx = 0;
    return dx;
}

Sint32 Mouse::getDY() const {
    auto dy = m_dy;
    m_dy = 0;
    return dy;
}
