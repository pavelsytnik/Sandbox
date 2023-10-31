#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include "State.hpp"

#include "../World/World.hpp"
#include "../Camera.hpp"
#include "../Mesh/Mesh.hpp"
#include "../Shader/BasicShader.hpp"
#include "../Texture/Texture.hpp"
#include "../Context.hpp"

class PlayingState : public State {

public:
    void handleInput() override;
    void update() override;
    void render() override;

    void resize();

    PlayingState(Context& context);
    //~PlayScene();

private:
    World m_world;
    Camera m_camera;
    Texture m_texture;
    
    Mesh m_mesh;
    BasicShader m_shader;
    Context& m_context;
};

#endif
