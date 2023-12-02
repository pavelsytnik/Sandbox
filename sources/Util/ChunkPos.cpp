#include "ChunkPos.hpp"

bool operator==(const ChunkPos& pos1, const ChunkPos& pos2) {
    return pos1.x == pos2.x && pos1.z == pos2.z;
}

namespace std {
	size_t hash<ChunkPos>::operator()(const ChunkPos& pos) const {
		hash<int32_t> hasher;
		return hash<int32_t>{}(hasher(pos.x) ^ hasher(pos.z) << 1);
	}
}
