#include "RenderMaster.hpp"

#include <SDL2/SDL.h>
#include <glad/glad.h>

void RenderMaster::swap(Window& window, State& state)
{
    //glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    state.render();

    window.swap();
}
