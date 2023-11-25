#ifndef BLOCKS_HPP
#define BLOCKS_HPP

#include "../Block/Block.hpp"
#include "../Util/Singleton.hpp"

class Blocks : public Singleton<Blocks> {

    friend class Singleton<Blocks>;

public:
    Block& AIR;
    Block& STONE;
    Block& GRASS;

private:
    Blocks();
};

#endif
