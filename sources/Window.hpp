#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>
#include <SDL2/SDL.h>

#include "Util/Destroyer/SDLWindowDestroyer.hpp"
#include "Util/Destroyer/SDLGLContextDestroyer.hpp"

class Window {
    
public:
    Window(const std::string& title, int width, int height);

    const std::string& getTitle() const;
    int getWidth() const;
    int getHeight() const;
    bool isMinimized() const;

    void handleEvent(const SDL_WindowEvent& event);
    void swap();

private:
    std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_window;
    std::unique_ptr<void, SDLGLContextDestroyer> m_context;

    std::string m_title;
    int m_width;
    int m_height;

    bool m_minimized;
};

#endif
