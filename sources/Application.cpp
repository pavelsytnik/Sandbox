#include "Application.hpp"

#include <iostream>

Application::Application() :
    m_sdlHolder{},
    m_registry{}, // redo in future
    m_running{false},
    m_window{"Sandbox", 800, 800},
    m_keyboard{},
    m_mouse{},
    m_state{}
{
    m_state = std::make_unique<PlayingState>(*this);
}

void Application::run() {

    float deltaTime = 0.f;
    Clock frameStart;
    m_running = true;

    while (m_running) {
        handleEvents();
        if (!m_window.isMinimized()) {
            m_state->handleInput();
        }
        m_state->update(deltaTime);
        if (!m_window.isMinimized()) {
            m_renderer.swap(m_window, *m_state);
        }

        deltaTime = frameStart.restart().asSeconds();
    }
}

const Keyboard& Application::getKeyboard() const {
    return m_keyboard;
}

const Window& Application::getWindow() const {
    return m_window;
}

const Mouse& Application::getMouse() const {
    return m_mouse;
}

bool Application::isRunning() const {
    return m_running;
}

void Application::handleEvents() {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT) {
            m_running = false;
        } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            m_keyboard.handleInput(event.key);
        } else if (event.type == SDL_MOUSEMOTION) {
            m_mouse.handleEvent(event.motion);
        } else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            m_mouse.handleEvent(event.button);
        } else if (event.type == SDL_WINDOWEVENT) {
            m_window.handleEvent(event.window);
        }
        m_state->handleEvent(event);
    }
}
