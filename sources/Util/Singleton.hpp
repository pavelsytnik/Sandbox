#ifndef SINGLETON_HPP
#define SINGLETON_HPP

template<typename T>
class Singleton {

public:
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static T& getInstance();
    static void deleteInstance();

protected:
    Singleton() = default;

private:
    static T* m_instance;
};

#include "Singleton.inl"

#endif
