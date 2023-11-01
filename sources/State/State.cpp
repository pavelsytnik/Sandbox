#include "State.hpp"

#include <glad/glad.h>

#include "../Application.hpp"

State::State(Application& app) : m_app(app) {

}

void State::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
            resize();
        }
    }
}

void State::resize() {
    int w, h;
    SDL_GetWindowSize(m_app.getContext().getWindow(), &w, &h);
    glViewport(0, 0, w, h);
}

State::~State() {}
