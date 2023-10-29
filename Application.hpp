#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

#include "Context.hpp"
#include "Scenes/Scene.hpp"
#include "Scenes/PlayScene.hpp"
#include "Input/Keyboard.hpp"

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

    std::unique_ptr<Scene> m_scene;
};

#endif
