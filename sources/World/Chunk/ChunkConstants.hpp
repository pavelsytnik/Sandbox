#ifndef CHUNK_CONSTANTS_HPP
#define CHUNK_CONSTANTS_HPP

#include <cstdint>

constexpr std::int32_t CHUNK_SIZE = 16;
constexpr std::int32_t CHUNK_AREA = CHUNK_SIZE * CHUNK_SIZE;
constexpr std::int32_t CHUNK_HEIGHT = 256;
constexpr std::int32_t CHUNK_VOLUME = CHUNK_AREA * CHUNK_SIZE;

constexpr std::int32_t CHUNK_SECTION_COUNT = 16;

#endif
