#include "Application.hpp"

#include <iostream>

Application::Application() : m_context{}, m_tessellator{} {


    running = false;



    glEnable(GL_DEPTH_TEST);

    m_tessellator.addVertex(0, 0, 0);
    m_tessellator.addTextureCoordinate(0, 0);
    m_tessellator.addVertex(0, 1, 0);
    m_tessellator.addTextureCoordinate(0, 0);
    m_tessellator.addVertex(1, 0, 0);
    m_tessellator.addTextureCoordinate(0, 0);

}

Application::~Application() {
}

void Application::run() {
    running = true;
    while (running) {
        handleEvents();
        render();
    }
}

void Application::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }
}

void Application::render() {

    glClearColor(1, 1, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_tessellator.flush();

    SDL_GL_SwapWindow(m_context.getWindow());
}
