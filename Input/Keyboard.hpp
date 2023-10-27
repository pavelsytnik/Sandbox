#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Key.hpp"

class Keyboard {
public:
    Keyboard() = delete;
    static Key forwardMove;
    static Key backwardMove;
    static Key leftMove;
    static Key rightMove;
    static Key jump;
    static Key sneak;

    static Key escape;
};

#endif
