#ifndef INPUT_LISTENERS_HPP
#define INPUT_LISTENERS_HPP

#include "../World/World.hpp"

void listenKeyInput(World& world);
void listenMouseInput(World& world);

void registerInputListeners();

#endif
