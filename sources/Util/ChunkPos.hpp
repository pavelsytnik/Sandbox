#ifndef CHUNK_POS_HPP
#define CHUNK_POS_HPP

#include <cstddef>
#include <functional>
#include <cstdint>

struct ChunkPos {
	std::int32_t x;
	std::int32_t z;
};

bool operator==(const ChunkPos& pos1, const ChunkPos& pos2);

template<>
struct std::hash<ChunkPos> {
	std::size_t operator()(const ChunkPos& pos) const;
};

#endif
