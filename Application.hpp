#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Context.hpp"

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
};

#endif
