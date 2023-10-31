#include "Keys.hpp"

inline KeyMapping* registerKey(const KeyMapping& key) {
    return Registry::registerKey(key);
}
