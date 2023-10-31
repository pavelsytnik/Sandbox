#ifndef KEY_MAPPINGS_HPP
#define KEY_MAPPINGS_HPP

#include <memory>

#include "../Input/KeyMapping.hpp"
#include "Registry.hpp"

class KeyMappings {

public:
    static KeyMappings& getInstance();
    static void deleteInstance();

    const std::shared_ptr<KeyMapping> FORWARD;
    const std::shared_ptr<KeyMapping> BACKWARD;
    const std::shared_ptr<KeyMapping> LEFT;
    const std::shared_ptr<KeyMapping> RIGHT;
    const std::shared_ptr<KeyMapping> UP;
    const std::shared_ptr<KeyMapping> DOWN;

private:
    KeyMappings();

    static KeyMappings* m_instance;
};

#endif
