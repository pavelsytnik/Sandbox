#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP

#include <string>
#include <memory>

#include "SDL2/SDL.h"

using image_t = std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)>;

class ImageLoader {

public:
    ImageLoader() = delete;
    static image_t loadPNG(std::string file);

private:
    static void flipVertically(image_t& image);
};

#endif
