template<typename T>
T* Singleton<T>::m_instance;

template<typename T>
T& Singleton<T>::getInstance() {
    if (!m_instance) {
        m_instance = new T;
    }
    return *m_instance;
}

template<typename T>
void Singleton<T>::deleteInstance() {
    delete m_instance;
    m_instance = nullptr;
}
