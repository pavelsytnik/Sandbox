#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>
#include <SDL2/SDL.h>

#include "Util/SDLWindowDestroyer.hpp"

class Window {
    
public:
    Window(SDL_Window& window);

    const std::string& getTitle() const;
    int getWidth() const;
    int getHeight() const;

    void handleEvent(const SDL_WindowEvent& event);
    void swap();

private:
    std::string m_title;
    int m_width;
    int m_height;

    SDL_Window& m_window;
};

#endif
