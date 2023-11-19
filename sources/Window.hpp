#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>
#include <SDL2/SDL.h>

#include "Util/SDLWindowDestroyer.hpp"

class Window {
    
public:
    Window(const std::string& title, int widht, int height);

    const std::string& getTitle() const;
    int getWidth() const;
    int getHeight() const;

    void handleInput(const SDL_WindowEvent& event);

private:
    std::string m_title;
    int m_width;
    int m_height;

    std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_window;
};

#endif
