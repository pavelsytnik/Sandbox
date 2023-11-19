#ifndef STATE_HPP
#define STATE_HPP

#include <cstdint>

#include <SDL2/SDL.h>

class Application;

class State {

public:
    State(Application& app);

    virtual void handleEvent(const SDL_Event& event) = 0;

    virtual void handleInput() = 0;
    virtual void update(std::uint64_t dt) = 0;
    virtual void render() = 0;

    virtual ~State() = 0;

protected:
    Application& m_app;
};

#endif
