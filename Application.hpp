#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Application {
public:
    Application();
    ~Application();
    void run();
private:
    void handleEvents();
    void render();
    SDL_Window* window;
    SDL_GLContext context;
    SDL_Renderer* renderer;
    bool running;
};

#endif
