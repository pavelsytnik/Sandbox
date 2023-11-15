#ifndef PATHS_HPP
#define PATHS_HPP

// TODO: implement constexpr string literal concatenation

namespace folders {

    constexpr auto resources = "resources/";
    constexpr auto shaders   = "resources/shaders/";
    constexpr auto textures  = "resources/images";
}

namespace files {
    
    constexpr auto blockAtlas          = "resources/images/blocks.png";

    constexpr auto basicVertexShader   = "resources/shaders/basic.vert";
    constexpr auto basicFragmentShader = "resources/shaders/basic.frag";

    constexpr auto chunkVertexShader   = "resources/shaders/chunk.vert";
    constexpr auto chunkFragmentShader = "resources/shaders/chunk.frag";
}

#endif
