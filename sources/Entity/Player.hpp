#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity {

    friend class World;
    
public:
    Player(World& world);

    //void setYaw(float yaw);
    //void setPitch(float pitch);

    //void setAcceleration(const glm::vec3& dir);
};

#endif
