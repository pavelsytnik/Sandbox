#ifndef SDL_GL_CONTEXT_DESTROYER_HPP
#define SDL_GL_CONTEXT_DESTROYER_HPP

#include <SDL2/SDL.h>

struct SDLGLContextDestroyer {
    inline void operator()(SDL_GLContext context) {
        SDL_GL_DeleteContext(context);
    }
};

#endif
