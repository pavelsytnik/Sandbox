#include "Context.hpp"

#include <SDL2/SDL_image.h>

#include "glad/glad.h"

Context::Context() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    m_window = SDL_CreateWindow(
        "Sandbox",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 800,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    configureGLContext();
    m_context = SDL_GL_CreateContext(m_window);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    glEnable(GL_DEPTH_TEST);
}

Context::~Context() {
    SDL_GL_DeleteContext(m_context);
    SDL_DestroyWindow(m_window);

    IMG_Quit();
    SDL_Quit();
}

SDL_Window* Context::getWindow() {
    return m_window;
}

void Context::configureGLContext() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}
