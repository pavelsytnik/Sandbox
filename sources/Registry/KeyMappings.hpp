#ifndef KEY_MAPPINGS_HPP
#define KEY_MAPPINGS_HPP

#include "../Input/KeyMapping.hpp"
#include "../Util/Singleton.hpp"

class KeyMappings : public Singleton<KeyMappings> {

    friend class Singleton<KeyMappings>;

public:
    KeyMapping& FORWARD;
    KeyMapping& BACKWARD;
    KeyMapping& LEFT;
    KeyMapping& RIGHT;
    KeyMapping& UP;
    KeyMapping& DOWN;

private:
    KeyMappings();
};

#endif
