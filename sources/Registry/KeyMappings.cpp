#include "KeyMappings.hpp"
#include "Registry.hpp"

#include <iostream>

KeyMappings* KeyMappings::m_instance;

KeyMappings::KeyMappings() :
    FORWARD(Registry::registerKey({SDL_SCANCODE_W})),
    BACKWARD(Registry::registerKey({SDL_SCANCODE_S})),
    LEFT(Registry::registerKey({SDL_SCANCODE_A})),
    RIGHT(Registry::registerKey({SDL_SCANCODE_D})),
    UP(Registry::registerKey({SDL_SCANCODE_SPACE})),
    DOWN(Registry::registerKey({SDL_SCANCODE_LSHIFT}))
{

}

KeyMappings& KeyMappings::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new KeyMappings;
        //std::cout << "instance\n";
    }
    return *m_instance;
}

void KeyMappings::deleteInstance() {
    delete m_instance;
    m_instance = nullptr;
}
