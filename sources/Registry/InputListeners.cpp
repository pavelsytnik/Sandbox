#include "InputListeners.hpp"

#include "KeyMappings.hpp"

#include <iostream>

void listenKeyInput(World& world) {
    static auto& keys = KeyMappings::getInstance();

    if (keys.FORWARD->heldDown()) {
    } else if (keys.BACKWARD->heldDown()) {
    } else if (keys.LEFT->heldDown()) {
    } else if (keys.RIGHT->heldDown()) {
    } else if (keys.UP->heldDown()) {
        std::cout << "UP\n";
    } else if (keys.DOWN->heldDown()) {
    }
}

void listenMouseInput(World& world) {

}

void registerInputListeners() {
    Registry::registerListener(listenKeyInput);
    Registry::registerListener(listenMouseInput);
}
