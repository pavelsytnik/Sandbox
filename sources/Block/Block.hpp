#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>

class Block {

public:
    Block(std::uint8_t id);
    //virtual bool isOpaque() = 0;
    //virtual bool isFullCube() = 0;
    std::uint8_t getID() const;

private:
    std::uint8_t m_id;
};

#endif
