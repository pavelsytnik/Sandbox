#include "FileReader.hpp"

#include <fstream>
#include <sstream>

std::string readEntire(const std::string& path) {
    std::ifstream file(path);
    std::stringstream stream;
    stream << file.rdbuf();
    file.close();
    return stream.str();
}
