#include "SDLHolder.hpp"

#include <cstdlib>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <glad/glad.h>

#include "Registry/KeyMappings.hpp"
#include "Registry/MouseButtonMappings.hpp"

SDLHolder::SDLHolder() {

    //std::cout << "Initializing SDL";
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "ERROR: Failed to initialize SDL\n";
        std::exit(EXIT_FAILURE);
    }
    //std::cout << std::endl;

    //std::cout << "Initializing SDL_image";
    int imgFlags = IMG_INIT_PNG;
    if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
        std::cout << "ERROR: Failed to initialize SDL_image\n";
        std::exit(EXIT_FAILURE);
    }
    //std::cout << std::endl;
}

SDLHolder::~SDLHolder() {

    IMG_Quit();
    SDL_Quit();
}
