#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <SDL2/SDL.h>

class Context {
public:
    Context();
    ~Context();
    SDL_Window* getWindow();
private:
    SDL_Window* m_window;
    SDL_GLContext m_context;
};

#endif
