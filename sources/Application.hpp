#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

#include "SDLHolder.hpp"
#include "State/State.hpp"
#include "State/PlayingState.hpp"
#include "Input/Keyboard.hpp"
#include "Input/Mouse.hpp"
#include "Util/Clock.hpp"
#include "Renderer/RenderMaster.hpp"
#include "Window.hpp"

class Application {

public:
    Application();
    void run();
    bool isRunning() const;
    //Context& getContext();

    const Mouse& getMouse() const;
    const Keyboard& getKeyboard() const;
    const Window& getWindow() const;

private:
    void handleEvents();

    SDLHolder* m_sdlHolder;
    bool m_running;
    bool m_visible;

    Window* m_window;
    Keyboard* m_keyboard;
    Mouse* m_mouse;

    RenderMaster* m_renderer;

    std::unique_ptr<State> m_state;
};

#endif
