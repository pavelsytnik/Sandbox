#include "ImageLoader.hpp"

#include <cstring>

#include "SDL2/SDL_image.h"

image_t ImageLoader::loadPNG(std::string file) {

    image_t image(nullptr, SDL_FreeSurface);
    image.reset(IMG_Load(file.c_str()));

    flipVertically(image);

    return image;
}

void ImageLoader::flipVertically(image_t& image) {

    Uint8* row = new Uint8[image->pitch];

    for (int i = 0; i < image->h / 2; i++) {

        Uint8* pixptr1 = (Uint8*)image->pixels + i * image->pitch;
        Uint8* pixptr2 = (Uint8*)image->pixels + (image->h - 1 - i) * image->pitch;

        std::memcpy(row, pixptr1, image->pitch);
        std::memcpy(pixptr1, pixptr2, image->pitch);
        std::memcpy(pixptr2, row, image->pitch);
    }

    delete[] row;
}
