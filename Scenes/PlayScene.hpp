#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include "Scene.hpp"

#include "../World/World.hpp"
#include "../Camera.hpp"
#include "../Mesh.hpp"
#include "../Shaders/BasicShader.hpp"
#include "../Texture/Texture.hpp"

class PlayScene : public Scene {

public:
    void handleInput() override;
    void update() override;
    void render() override;

    PlayScene();
    //~PlayScene();

private:
    World m_world;
    Camera m_camera;
    Texture m_texture;
    
    Mesh m_mesh;
    BasicShader m_shader;
};

#endif
