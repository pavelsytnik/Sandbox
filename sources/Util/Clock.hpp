#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <cstdint>

#include "Time.hpp"

class Clock {

public:
    Clock();
    Time restart();
    Time getElapsedTime() const;

private:
    std::int64_t m_startTime;
};

#endif
