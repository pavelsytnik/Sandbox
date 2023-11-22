#include "Window.hpp"

#include <glad/glad.h>
#include <iostream>

Window::Window(SDL_Window& window) : m_window(window), m_minimized(false) {

    m_title = SDL_GetWindowTitle(&window);
    SDL_GetWindowSize(&window, &m_width, &m_height);
}

const std::string& Window::getTitle() const {
    return m_title;
}

int Window::getWidth() const {
    return m_width;
}

int Window::getHeight() const {
    return m_height;
}

bool Window::isMinimized() const {
    return m_minimized;
}

void Window::handleEvent(const SDL_WindowEvent& event) {
    if (event.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
        SDL_GetWindowSize(&m_window, &m_width, &m_height);
        glViewport(0, 0, m_width, m_height);
    }
    else if (event.event == SDL_WINDOWEVENT_MINIMIZED) {
        m_minimized = true;
    }
    else if (event.event == SDL_WINDOWEVENT_RESTORED) {
        m_minimized = false;
    }
}

void Window::swap() {
    SDL_GL_SwapWindow(&m_window);
}
