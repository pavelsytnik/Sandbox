#ifndef RENDER_MASTER_HPP
#define RENDER_MASTER_HPP

#include "../State/State.hpp"
#include "../Window.hpp"

class RenderMaster {

public:
    void swap(Window& window, State& state);
};

#endif
