#include "Clock.hpp"

#include <chrono>

namespace {
    using namespace std::chrono;

    constexpr std::int64_t now() {
        return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    }
}

Clock::Clock() :
    m_startTime(now())
{}

Time Clock::getElapsedTime() const {
    return Time::nanoseconds(now() - m_startTime);
}

Time Clock::restart() {
    auto oldStartTime = m_startTime;
    m_startTime = now();
    return Time::nanoseconds(m_startTime - oldStartTime);
}
