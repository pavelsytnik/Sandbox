#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include "State.hpp"

#include "../Camera.hpp"
#include "../Entity/Player.hpp"
#include "../Input/Mouse.hpp"
#include "../Registry/MouseButtonMappings.hpp"
#include "../Registry/KeyMappings.hpp"
#include "../World/World.hpp"
#include "../Mesh/ChunkMesh.hpp"
#include "../Renderer/ChunkRenderer.hpp"

#include <memory>

class PlayingState : public State {

public:
    void handleEvent(const SDL_Event& event) override;
    void handleInput() override;
    void update(float dt) override;
    void render() override;

    PlayingState(Application& app);

private:
    void mouseInput();
    void keyboardInput();

    World m_world;
    Player& m_player;

    std::shared_ptr<ChunkMesh> m_chunkMesh;

    Camera m_camera;
    ChunkRenderer m_chunkRenderer;

    MouseButtonMappings& m_buttons;
    KeyMappings& m_keys;

    const Mouse& m_mouse;
};

#endif
