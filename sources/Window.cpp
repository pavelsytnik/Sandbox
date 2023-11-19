#include "Window.hpp"

#include <iostream>
#include <glad/glad.h>

Window::Window(const std::string& title, int width, int height) {

    m_window.reset(SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    ));

    if (m_window == nullptr) {
        std::cout << "ERROR: Failed to create window\n";
        std::exit(EXIT_FAILURE);
    }

    m_title = title;
    m_width = width;
    m_height = height;
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

void Window::handleInput(const SDL_WindowEvent& event) {
    if (event.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
        int w, h;
        SDL_GetWindowSize(m_window.get(), &w, &h);
        glViewport(0, 0, w, h);
    }
}
