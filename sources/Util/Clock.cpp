#include "Clock.hpp"

#include <chrono>

namespace {
    using namespace std::chrono;

    inline std::uint64_t now() {
        return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    }
}

Clock::Clock() :
    m_startTime(now())
{}

std::uint64_t Clock::getElapsedTime() const {
    return now() - m_startTime;
}

std::uint64_t Clock::restart() {
    auto oldStartTime = m_startTime;
    m_startTime = now();
    return m_startTime - oldStartTime;
}
