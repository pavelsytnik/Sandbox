#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include "State.hpp"

#include "../World/World.hpp"
#include "../Camera.hpp"
#include "../Mesh/Mesh.hpp"
#include "../Shader/BasicShader.hpp"
#include "../Texture/Texture.hpp"
#include "../Context.hpp"
#include "../Input/KeyMapping.hpp"
#include "../Registry/KeyMappings.hpp"
#include "../Registry/Registry.hpp"
#include "../Registry/InputListeners.hpp"

class PlayingState : public State {

public:
    void handleEvent(const SDL_Event& event) override;
    void handleInput() override;
    void update() override;
    void render() override;

    PlayingState(Application& app);
    //~PlayScene();

protected:
    void resize() override;

private:
    World m_world;
    Camera m_camera;
    Texture m_texture;
    
    Mesh m_mesh;
    BasicShader m_shader;

    KeyMappingPointers m_keys;
    std::vector<InputListener> m_listeners;
};

#endif
