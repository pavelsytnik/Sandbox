#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include "State.hpp"

#include "../Camera.hpp"
#include "../Entity/Player.hpp"
#include "../Mesh/Mesh.hpp"
#include "../Registry/KeyMappings.hpp"
#include "../Shader/BasicShader.hpp"
#include "../Texture/Texture.hpp"
#include "../World/World.hpp"

class PlayingState : public State {

public:
    void handleEvent(const SDL_Event& event) override;
    void handleInput() override;
    void update() override;
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
    Texture m_texture;
    Mesh m_mesh;
    BasicShader m_shader;

    KeyMappings& m_keys;
};

#endif
