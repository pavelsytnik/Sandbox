#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>

#include "glad/glad.h"

class Texture {
public:
    Texture(std::string path);
    Texture(const Texture&) = delete;
    ~Texture();
    GLuint id();
private:
    GLuint m_id;
};

#endif
