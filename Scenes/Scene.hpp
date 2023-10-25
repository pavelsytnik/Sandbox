#ifndef SCENE_HPP
#define SCENE_HPP

class Scene {

public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual ~Scene() = 0;
};

#endif
