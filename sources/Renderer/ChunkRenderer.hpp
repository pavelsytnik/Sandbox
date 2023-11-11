#ifndef CHUNK_RENDERER_HPP
#define CHUNK_RENDERER_HPP

class ChunkMesh;

class ChunkRenderer {

public:
    void add(const ChunkMesh& mesh);
    void render();

private:
    // TODO: ChunkMesh info for rendering
};

#endif
