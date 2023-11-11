#include "RenderMaster.hpp"

#include <glad/glad.h>

void RenderMaster::swap(SDL_Window* window)
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SDL_GL_SwapWindow(window);
}
