#ifndef KEYS_HPP
#define KEYS_HPP

#include "../Input/KeyMapping.hpp"
#include "Registry.hpp"

KeyMapping* registerKey(const KeyMapping& key);

KeyMapping* const FORWARD_KEY = registerKey(KeyMapping(SDL_SCANCODE_W));
KeyMapping* const BACKWARD_KEY = registerKey(KeyMapping(SDL_SCANCODE_S));
KeyMapping* const LEFT_KEY = registerKey(KeyMapping(SDL_SCANCODE_A));
KeyMapping* const RIGHT_KEY = registerKey(KeyMapping(SDL_SCANCODE_D));
KeyMapping* const UP_KEY = registerKey(KeyMapping(SDL_SCANCODE_SPACE));
KeyMapping* const DOWN_KEY = registerKey(KeyMapping(SDL_SCANCODE_LSHIFT));

#endif
