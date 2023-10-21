#include "Application.hpp"

#include <iostream>

Application::Application() :
    m_context{},
    m_running{false}
{}

void Application::run() {
    m_running = true;
    while (m_running) {
        handleEvents();
        render();
    }
}

bool Application::isRunning() {
    return m_running;
}

Context& Application::getContext() {
    return m_context;
}

void Application::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            m_running = false;
        }
    }
}

void Application::render() {

    SDL_GL_SwapWindow(m_context.getWindow());
}
