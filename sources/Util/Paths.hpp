#ifndef PATHS_HPP
#define PATHS_HPP

// TODO: implement constexpr string literal concatenation

namespace folders {

    constexpr auto resources = "resources/";
    constexpr auto shaders   = "resources/shaders/";
    constexpr auto textures  = "resources/textures/";
}

namespace files {
    
    constexpr auto blockAtlas          = "blocks";

    constexpr auto basicVertexShader   = "basic";
    constexpr auto basicFragmentShader = "basic";

    constexpr auto chunkVertexShader   = "chunk";
    constexpr auto chunkFragmentShader = "chunk";
}

#endif
