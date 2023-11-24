#ifndef KEY_MAPPINGS_HPP
#define KEY_MAPPINGS_HPP

#include <memory>

#include "../Input/KeyMapping.hpp"
#include "Registry.hpp"
#include "../Util/Singleton.hpp"

class KeyMappings : public Singleton<KeyMappings> {

    friend class Singleton<KeyMappings>;

public:
    const std::shared_ptr<KeyMapping> FORWARD;
    const std::shared_ptr<KeyMapping> BACKWARD;
    const std::shared_ptr<KeyMapping> LEFT;
    const std::shared_ptr<KeyMapping> RIGHT;
    const std::shared_ptr<KeyMapping> UP;
    const std::shared_ptr<KeyMapping> DOWN;

private:
    KeyMappings();
};

#endif
