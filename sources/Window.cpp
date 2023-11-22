#include "Window.hpp"

#include <glad/glad.h>
#include <iostream>

Window::Window(const std::string& title, int width, int height) : m_minimized(false) {

    m_window.reset(SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    width, height,
                                    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)
    );
    if (m_window == nullptr) {
        std::cout << "ERROR: Failed to create window\n";
        std::exit(EXIT_FAILURE);
    }

    m_context.reset(SDL_GL_CreateContext(m_window.get()));
    if (m_context == nullptr) {
        std::cout << "ERROR: Failed to create GL context\n";
        std::exit(EXIT_FAILURE);
    }

    if (gladLoadGLLoader(SDL_GL_GetProcAddress) == 0) {
        std::cout << "ERROR: Failed to load GL loader\n";
        std::exit(EXIT_FAILURE);
    }

    m_title = SDL_GetWindowTitle(m_window.get());
    SDL_GetWindowSize(m_window.get(), &m_width, &m_height);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    glEnable(GL_DEPTH_TEST);
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
        SDL_GetWindowSize(m_window.get(), &m_width, &m_height);
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
    SDL_GL_SwapWindow(m_window.get());
}
