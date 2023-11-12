#ifndef FACES_HPP
#define FACES_HPP

#include <array>
#include <glad/glad.h>

namespace faces {

    constexpr std::array<GLfloat, 18> back   = {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0};
    constexpr std::array<GLfloat, 18> front  = {0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1};
    constexpr std::array<GLfloat, 18> left   = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
    constexpr std::array<GLfloat, 18> right  = {1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1};
    constexpr std::array<GLfloat, 18> bottom = {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0};
    constexpr std::array<GLfloat, 18> top    = {0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0};
}

#endif
