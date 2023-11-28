constexpr Time Time::nanoseconds(std::int64_t ns) {
    return std::chrono::nanoseconds(ns);
}

constexpr Time Time::milliseconds(std::int32_t ms) {
    return std::chrono::milliseconds(ms);
}

constexpr Time Time::seconds(float s) {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<float>(s));
}

constexpr std::int64_t Time::asNanoseconds() const {
    return m_nanoseconds.count();
}

constexpr std::int32_t Time::asMilliseconds() const {
    return std::chrono::duration_cast<std::chrono::duration<std::int32_t, std::milli>>(m_nanoseconds).count();
}

constexpr float Time::asSeconds() const {
    return std::chrono::duration<float>(m_nanoseconds).count();
}

constexpr Time::Time(std::chrono::nanoseconds nanoseconds) :
    m_nanoseconds(nanoseconds)
{}
