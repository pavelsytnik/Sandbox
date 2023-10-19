#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Context.hpp"
#include "Tessellator.hpp"

class Application {
public:
    Application();
    ~Application();
    void run();
private:
    void handleEvents();
    void render();

    Context m_context;
    Tessellator m_tessellator;

    bool running;
};

#endif
