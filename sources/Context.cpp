#include "Context.hpp"

#include <cstdlib>
#include <iostream>

#include <SDL2/SDL_image.h>

#include <glad/glad.h>

Context::Context() {

    //std::cout << "Initializing SDL";
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "ERROR: Failed to initialize SDL\n";
        std::exit(EXIT_FAILURE);
    }
    //std::cout << std::endl;

    //std::cout << "Initializing SDL_image";
    int imgFlags = IMG_INIT_PNG;
    if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
        std::cout << "ERROR: Failed to initialize SDL_image\n";
        std::exit(EXIT_FAILURE);
    }
    //std::cout << std::endl;

    m_window = SDL_CreateWindow(
        "Sandbox",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 800,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    if (m_window == nullptr) {
        std::cout << "ERROR: Failed to create window\n";
        std::exit(EXIT_FAILURE);
    }

    configureGLContext();
    m_context = SDL_GL_CreateContext(m_window);
    if (m_context == nullptr) {
        std::cout << "ERROR: Failed to create GL context\n";
        std::exit(EXIT_FAILURE);
    }

    if (gladLoadGLLoader(SDL_GL_GetProcAddress) == 0) {
        std::cout << "ERROR: Failed to load GL loader\n";
        std::exit(EXIT_FAILURE);
    }

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
