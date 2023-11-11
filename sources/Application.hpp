#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

#include "Context.hpp"
#include "State/State.hpp"
#include "State/PlayingState.hpp"
#include "Input/Keyboard.hpp"
#include "Input/Mouse.hpp"
#include "Util/Clock.hpp"
#include "Renderer/RenderMaster.hpp"

class Application {

public:
    Application();
    void run();
    bool isRunning() const;
    Context& getContext();

    const Mouse& getMouse() const;
    const Keyboard& getKeyboard() const;

private:
    void handleEvents();

    Context m_context;
    bool m_running;
    bool m_visible;

    Keyboard m_keyboard;
    Mouse m_mouse;

    RenderMaster m_renderer;

    std::unique_ptr<State> m_state;
};

#endif
