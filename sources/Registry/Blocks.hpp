#ifndef BLOCKS_HPP
#define BLOCKS_HPP

#include <memory>

#include "../Block/Block.hpp"
#include "../Util/Singleton.hpp"

class Blocks : public Singleton<Blocks> {

    friend class Singleton<Blocks>;

public:
    const std::shared_ptr<Block> AIR;
    const std::shared_ptr<Block> STONE;
    const std::shared_ptr<Block> GRASS;

private:
    Blocks();
};

#endif
