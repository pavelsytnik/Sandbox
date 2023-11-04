#include "MouseButtonMappings.hpp"
#include "../Input/MouseButtonMapping.hpp"

MouseButtonMappings* MouseButtonMappings::m_instance;

MouseButtonMappings::MouseButtonMappings() :
    BREAK(Registry::registerMouseButton({SDL_BUTTON_LEFT})),
    PUT(Registry::registerMouseButton({SDL_BUTTON_RIGHT})),
    SELECT(Registry::registerMouseButton({SDL_BUTTON_MIDDLE}))
{}

MouseButtonMappings& MouseButtonMappings::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new MouseButtonMappings;
    }
    return *m_instance;
}

void MouseButtonMappings::deleteInstance() {
    delete m_instance;
    m_instance = nullptr;
}
