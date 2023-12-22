#ifndef CHUNK_RENDERER_HPP
#define CHUNK_RENDERER_HPP

#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>
#include <cstddef>

#include <glm/glm.hpp>

#include "../Shader/BasicShader.hpp"
#include "../Mesh/ChunkMesh.hpp"
#include "../Texture/Texture.hpp"
#include "../World/Chunk/Chunk.hpp"

class Camera;

template<>
struct std::hash<glm::ivec3> {
    inline bool operator()(const glm::ivec3& a, const glm::ivec3& b) const {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }
    inline std::size_t operator()(const glm::ivec3& v) const {
        return std::hash<int>{}(std::hash<int>()(v.x) ^ ((std::hash<int>()(v.y)) ^ (std::hash<int>()(v.z) << 1) << 1));
    }

};

class ChunkRenderer {

public:
    ChunkRenderer();

    //void add(const std::shared_ptr<ChunkMesh>& mesh);
    void add(const ChunkSection& chunk);
    void clear();
    void render(const Camera& camera);

private:
    BasicShader m_shader;
    std::unordered_map<glm::ivec3, std::unique_ptr<ChunkMesh>> m_meshes;
    Texture m_atlas;
};




#endif
