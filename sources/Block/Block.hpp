#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>

class Block {

public:
    Block(std::uint8_t id);

    //virtual bool isOpaque();
    //virtual bool isFullCube();
    virtual bool isAir() const;

    std::uint8_t getID() const;

private:
    std::uint8_t m_id;
};

#endif
