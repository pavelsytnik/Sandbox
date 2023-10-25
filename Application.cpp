#include "Application.hpp"

#include <iostream>

Application::Application() :
    m_context{},
    m_running{false},
    m_scene{new PlayScene}
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
    glClearColor(1.f, 0.0f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_scene->render();
    SDL_GL_SwapWindow(m_context.getWindow());
}
