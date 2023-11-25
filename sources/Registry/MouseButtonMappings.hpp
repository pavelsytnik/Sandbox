#ifndef MOUSE_BUTTON_MAPPINGS_HPP
#define MOUSE_BUTTON_MAPPINGS_HPP

#include "../Input/MouseButtonMapping.hpp"
#include "../Util/Singleton.hpp"

class MouseButtonMappings : public Singleton<MouseButtonMappings> {

    friend class Singleton<MouseButtonMappings>;

public:
    MouseButtonMapping& BREAK;
    MouseButtonMapping& PUT;
    MouseButtonMapping& SELECT;

private:
    MouseButtonMappings();
};

#endif
