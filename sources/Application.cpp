#include "Application.hpp"

#include <iostream>

#include "Registry/KeyMappings.hpp"

Application::Application() :
    m_context{}, // load Registry also
    m_running{false},
    m_state{}
{
    KeyMappings::getInstance();
    m_state = std::make_unique<PlayingState>(*this);
}

void Application::run() {
    m_running = true;
    while (m_running) {
        handleEvents();
        m_state->update();
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
        m_state->handleEvent(event);
        if (event.type == SDL_QUIT) {
            m_running = false;
        } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            m_keyboard.handleInput(event.key);
        }
        m_state->handleInput();
    }
}

void Application::render() {
    glClearColor(0.5f, 0.8f, 1.0f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_state->render();
    SDL_GL_SwapWindow(m_context.getWindow());
}
