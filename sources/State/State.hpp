#ifndef STATE_HPP
#define STATE_HPP

#include <SDL2/SDL.h>

#include "../Context.hpp"

class State {

public:
    State(Context& context);

    virtual void handleEvent(const SDL_Event& event);

    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual ~State() = 0;

protected:
    virtual void resize();
    Context& m_context;
};

#endif
