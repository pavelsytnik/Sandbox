#ifndef FACES_HPP
#define FACES_HPP

#include <array>
#include <glad/glad.h>

namespace faces {

    constexpr std::array<GLfloat, 12> back   = {0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0};
    constexpr std::array<GLfloat, 12> front  = {0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
    constexpr std::array<GLfloat, 12> left   = {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0};
    constexpr std::array<GLfloat, 12> right  = {1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0};
    constexpr std::array<GLfloat, 12> bottom = {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1};
    constexpr std::array<GLfloat, 12> top    = {0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1};
}

#endif
