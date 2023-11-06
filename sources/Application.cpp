#include "Application.hpp"

#include <iostream>

#include "Registry/KeyMappings.hpp"

Application::Application() :
    m_context{}, // load Registry also
    m_running{false},
    m_visible{true},
    m_state{}
{
    KeyMappings::getInstance();
    m_state = std::make_unique<PlayingState>(*this);
}

void Application::run() {

    auto deltaTime = 0ULL;
    Clock frameStart;
    m_running = true;

    while (m_running) {
        handleEvents();
        if (m_visible) {
            m_state->handleInput();
        }
        m_state->update(deltaTime);
        if (m_visible) {
            render();
        }

        deltaTime = frameStart.restart();
    }
}

const Keyboard& Application::getKeyboard() const {
    return m_keyboard;
}

const Mouse& Application::getMouse() const {
    return m_mouse;
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
        } else if (event.type == SDL_MOUSEMOTION) {
            m_mouse.handleEvent(event.motion);
        } else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            m_mouse.handleEvent(event.button);
        }
    }

    if (SDL_GetWindowFlags(m_context.getWindow()) & SDL_WINDOW_MINIMIZED && m_visible) {
        m_visible = false;
    } else if (!(SDL_GetWindowFlags(m_context.getWindow()) & SDL_WINDOW_MINIMIZED) && !m_visible) {
        m_visible = true;
    }
}

void Application::render() {
    glClearColor(0.5f, 0.8f, 1.0f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_state->render();
    SDL_GL_SwapWindow(m_context.getWindow());
}
