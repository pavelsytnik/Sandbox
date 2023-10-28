#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Context.hpp"
#include "Scenes/Scene.hpp"
#include "Scenes/PlayScene.hpp"
#include "Input/Keyboard.hpp"

//#include <memory>

class Application {

public:
    Application();
    void run();
    bool isRunning();
    Context& getContext();

private:
    void handleEvents();
    void render();

    Context m_context;
    bool m_running;

    Keyboard m_keyboard;

    Scene* m_scene;
};

#endif
