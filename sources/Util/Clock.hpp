#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <cstdint>

class Clock {

public:
    Clock();
    std::uint64_t restart();
    std::uint64_t getElapsedTime() const;

private:
    std::uint64_t m_startTime;
};

#endif
