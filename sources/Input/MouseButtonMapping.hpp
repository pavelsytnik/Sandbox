#ifndef MOUSE_BUTTON_MAPPING_HPP
#define MOUSE_BUTTON_MAPPING_HPP

#include <SDL2/SDL.h>

#include "Mouse.hpp"

class MouseButtonMapping {

    friend class Mouse;

public:
    MouseButtonMapping(Uint8 button);
    void setButton(Uint8 button);
    Uint8 getButton() const;
    bool heldDown() const;

private:
    bool m_heldDown;
    Uint8 m_button;
};

#endif

