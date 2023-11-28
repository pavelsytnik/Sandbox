#ifndef TIME_HPP
#define TIME_HPP

#include <cstdint>
#include <chrono>

class Time {
    
public:
    Time(Time&&) = default;
    Time(const Time&) = default;

    static constexpr Time nanoseconds(std::int64_t ns);
    static constexpr Time milliseconds(std::int32_t ms);
    static constexpr Time seconds(float s);

    constexpr std::int64_t asNanoseconds() const;
    constexpr std::int32_t asMilliseconds() const;
    constexpr float asSeconds() const;

private:
    constexpr Time(std::chrono::nanoseconds nanoseconds);

    std::chrono::nanoseconds m_nanoseconds;
};

#include "Time.inl"

#endif
