#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

#include "Holder/SDLHolder.hpp"
#include "State/State.hpp"
#include "State/PlayingState.hpp"
#include "Input/Keyboard.hpp"
#include "Input/Mouse.hpp"
#include "Util/Clock.hpp"
#include "Renderer/RenderMaster.hpp"
#include "Window.hpp"
#include "Holder/RegistryHolder.hpp"

class Application {

public:
    Application();
    void run();
    bool isRunning() const;

    const Mouse& getMouse() const;
    const Keyboard& getKeyboard() const;
    const Window& getWindow() const;

private:
    void handleEvents();

    SDLHolder m_sdlHolder;
    RegistryHolder m_registry;

    bool m_running;

    Window m_window;
    Keyboard m_keyboard;
    Mouse m_mouse;

    RenderMaster m_renderer;

    std::unique_ptr<State> m_state;
};

#endif
