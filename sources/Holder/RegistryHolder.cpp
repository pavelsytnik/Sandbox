#include "RegistryHolder.hpp"
#include "../Registry/KeyMappings.hpp"
#include "../Registry/MouseButtonMappings.hpp"
#include "../Registry/Blocks.hpp"

#include "BlockModelHolder.hpp"

RegistryHolder::RegistryHolder() {
    KeyMappings::getInstance();
    MouseButtonMappings::getInstance();
    Blocks::getInstance();
    BlockModelHolder::getInstance();
}

RegistryHolder::~RegistryHolder() {
    BlockModelHolder::deleteInstance();
    Blocks::deleteInstance();
    MouseButtonMappings::deleteInstance();
    KeyMappings::deleteInstance();
}
