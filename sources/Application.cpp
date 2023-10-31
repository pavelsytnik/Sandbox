#include "Application.hpp"

#include <iostream>

Application::Application() :
    m_context{},
    m_running{false},
    m_scene{std::make_unique<PlayScene>()}
{}

void Application::run() {
    m_running = true;
    while (m_running) {
        handleEvents();
        m_scene->update();
        render();
    }
}

bool Application::isRunning() const {
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
        } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            m_keyboard.handleInput(event.key);
        }
        m_scene->handleInput();
    }
}

void Application::render() {
    glClearColor(0.5f, 0.8f, 1.0f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_scene->render();
    SDL_GL_SwapWindow(m_context.getWindow());
}
