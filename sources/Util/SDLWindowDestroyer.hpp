#ifndef SDL_WINDOW_DESTROYER_HPP
#define SDL_WINDOW_DESTROYER_HPP

#include <SDL2/SDL.h>

struct SDLWindowDestroyer {

    inline void operator()(SDL_Window* window) {
        SDL_DestroyWindow(window);
    }
};

#endif
