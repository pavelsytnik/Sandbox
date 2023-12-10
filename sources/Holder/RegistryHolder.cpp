#include "RegistryHolder.hpp"
#include "../Registry/KeyMappings.hpp"
#include "../Registry/MouseButtonMappings.hpp"
#include "../Registry/Blocks.hpp"

RegistryHolder::RegistryHolder() {
    KeyMappings::getInstance();
    MouseButtonMappings::getInstance();
    Blocks::getInstance();
}

RegistryHolder::~RegistryHolder() {
    Blocks::deleteInstance();
    MouseButtonMappings::deleteInstance();
    KeyMappings::deleteInstance();
}
