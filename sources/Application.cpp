#include "Application.hpp"

#include <iostream>

Application::Application() :
    m_sdlHolder{new SDLHolder()},
    m_running{false},
    m_visible{true},
    m_window{new Window(*m_sdlHolder->getWindow())},
    m_keyboard{new Keyboard()},
    m_mouse{new Mouse()},
    m_state{}
{
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
            m_renderer->swap(*m_window, *m_state);
        }

        deltaTime = frameStart.restart();
    }
}

const Keyboard& Application::getKeyboard() const {
    return *m_keyboard;
}

const Window& Application::getWindow() const {
    return *m_window;
}

const Mouse& Application::getMouse() const {
    return *m_mouse;
}

bool Application::isRunning() const {
    return m_running;
}

//Context& Application::getContext() {
//    return m_context;
//}

void Application::handleEvents() {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT) {
            m_running = false;
        } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            m_keyboard->handleInput(event.key);
        } else if (event.type == SDL_MOUSEMOTION) {
            m_mouse->handleEvent(event.motion);
        } else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            m_mouse->handleEvent(event.button);
        } else if (event.type == SDL_WINDOWEVENT) {
            m_window->handleEvent(event.window);
        }
        m_state->handleEvent(event);
    }


    if (SDL_GetWindowFlags(m_sdlHolder->getWindow()) & SDL_WINDOW_MINIMIZED && m_visible) {
        m_visible = false;
    } else if (!(SDL_GetWindowFlags(m_sdlHolder->getWindow()) & SDL_WINDOW_MINIMIZED) && !m_visible) {
        m_visible = true;
    }
}
