#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

#include "Context.hpp"
#include "State/State.hpp"
#include "State/PlayingState.hpp"
#include "Input/Keyboard.hpp"
#include "Input/Mouse.hpp"

class Application {

public:
    Application();
    void run();
    bool isRunning() const;
    Context& getContext();

private:
    void handleEvents();
    void render();

    Context m_context;
    bool m_running;

    Keyboard m_keyboard;
    Mouse m_mouse;

    std::unique_ptr<State> m_state;
};

#endif
