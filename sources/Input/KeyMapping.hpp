#ifndef KEY_MAPPING_HPP
#define KEY_MAPPING_HPP

#include <SDL2/SDL.h>

class KeyMapping {

public:
    KeyMapping(SDL_Scancode scancode);
    bool heldDown() const;
    void setScancode(SDL_Scancode scancode);
    SDL_Scancode getScancode() const;

private:
    friend void update(KeyMapping& key, const SDL_KeyboardEvent& event);

    SDL_Scancode m_scancode;
    bool m_heldDown;
};

#endif
