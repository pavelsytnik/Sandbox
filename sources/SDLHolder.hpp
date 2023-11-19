#ifndef SDL_HOLDER_HPP
#define SDL_HOLDER_HPP

#include <SDL2/SDL.h>

class SDLHolder {

public:
    SDLHolder();
    ~SDLHolder();
    SDL_Window* getWindow();

private:
    void configureGLContext();
    SDL_Window* m_window;
    SDL_GLContext m_context;
};

#endif
