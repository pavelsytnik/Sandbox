#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include "Scene.hpp"

#include "../World/World.hpp"
#include "../Camera.hpp"
#include "../Mesh/Mesh.hpp"
#include "../Shader/BasicShader.hpp"
#include "../Texture/Texture.hpp"
#include "../Context.hpp"

class PlayScene : public Scene {

public:
    void handleInput() override;
    void update() override;
    void render() override;

    void resize();

    PlayScene(Context& context);
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
