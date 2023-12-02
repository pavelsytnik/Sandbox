cmake_minimum_required(VERSION 3.16)
project(sandbox)

set(SOURCE
    sources/Application.cpp
    sources/Camera.cpp
    sources/Main.cpp
    sources/RegistryHolder.cpp
    sources/SDLHolder.cpp
    sources/Window.cpp
    sources/Block/Block.cpp
    sources/Block/AirBlock.cpp
    sources/Entity/Entity.cpp
    sources/Entity/Player.cpp
    sources/Input/Keyboard.cpp
    sources/Input/KeyMapping.cpp
    sources/Input/Mouse.cpp
    sources/Input/MouseButtonMapping.cpp
    sources/Mesh/ChunkMesh.cpp
    sources/Mesh/ChunkMeshBuilder.cpp
    sources/Mesh/ElementBuffer.cpp
    sources/Mesh/Mesh.cpp
    sources/Mesh/VertexArray.cpp
    sources/Mesh/VertexBuffer.cpp
    sources/Registry/Blocks.cpp
    sources/Registry/KeyMappings.cpp
    sources/Registry/MouseButtonMappings.cpp
    sources/Registry/Registry.cpp
    sources/Renderer/ChunkRenderer.cpp
    sources/Renderer/RenderMaster.cpp
    sources/Shader/BasicShader.cpp
    sources/Shader/Shader.cpp
    sources/Shader/ShaderLoader.cpp
    sources/Shader/UniformLoader.cpp
    sources/State/PlayingState.cpp
    sources/State/State.cpp
    sources/Texture/BlocksAtlas.cpp
    sources/Texture/Texture.cpp
    sources/Util/ChunkPos.cpp
    sources/Util/Clock.cpp
    sources/Util/FileReader.cpp
    sources/Util/ImageLoader.cpp
    sources/World/World.cpp
    sources/World/Chunk/Chunk.cpp)

add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/resources
    ${PROJECT_BINARY_DIR}/$<CONFIGURATION>/resources)

include(cmake/path_to_sdl2.cmake)

list(APPEND CMAKE_PREFIX_PATH ${SDL2_PATH})
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E copy_if_different
         ${SDL2_DLLS}
         $<TARGET_FILE_DIR:${PROJECT_NAME}>)

add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glm)

if(MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DPI_AWARE "PerMonitor")
endif(MSVC)

target_include_directories(${PROJECT_NAME} PRIVATE dependencies)

target_link_libraries(${PROJECT_NAME}
    glad
    glm
    ${SDL2_LIBRARIES}
)
