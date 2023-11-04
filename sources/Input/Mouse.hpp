#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <SDL2/SDL.h>

#include "../Registry/Registry.hpp"

class MouseButtonMapping;

class Mouse {

public:
    Mouse();
    void handleEvent(const SDL_MouseMotionEvent& event);
    void handleEvent(const SDL_MouseButtonEvent& event);

    Sint32 getDX() const;
    Sint32 getDY() const;

private:
    void update(MouseButtonMapping& button, const SDL_MouseButtonEvent& event);

    ButtonPointers m_buttons;
    mutable Sint32 m_dx, m_dy;
};

#endif
