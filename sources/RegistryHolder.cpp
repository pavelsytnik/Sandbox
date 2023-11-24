#include "RegistryHolder.hpp"
#include "Registry/KeyMappings.hpp"
#include "Registry/MouseButtonMappings.hpp"

RegistryHolder::RegistryHolder() {
    KeyMappings::getInstance();
    MouseButtonMappings::getInstance();
}

RegistryHolder::~RegistryHolder() {
    MouseButtonMappings::deleteInstance();
    KeyMappings::deleteInstance();
}
