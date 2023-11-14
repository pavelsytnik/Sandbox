#ifndef RENDER_MASTER_HPP
#define RENDER_MASTER_HPP

#include <SDL2/SDL.h>

#include "../State/State.hpp"

class RenderMaster {

public:
    void swap(SDL_Window* window, State& state);
};

#endif
