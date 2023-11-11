#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include "State.hpp"

#include "../Camera.hpp"
#include "../Entity/Player.hpp"
#include "../Input/Mouse.hpp"
#include "../Registry/MouseButtonMappings.hpp"
#include "../Registry/KeyMappings.hpp"
#include "../World/World.hpp"

class PlayingState : public State {

public:
    void handleEvent(const SDL_Event& event) override;
    void handleInput() override;
    void update(std::uint64_t dt) override;
    void render() override;

    PlayingState(Application& app);

protected:
    void resize() override;

private:
    void mouseInput();
    void keyboardInput();

    World m_world;
    Player& m_player;

    Camera m_camera;

    MouseButtonMappings& m_buttons;
    KeyMappings& m_keys;

    const Mouse& m_mouse;
};

#endif
