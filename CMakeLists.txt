cmake_minimum_required(VERSION 3.16)
project(sandbox)

set(SOURCE
    sources/Input/KeyMapping.cpp
    sources/Input/Keyboard.cpp
    sources/Mesh/Mesh.cpp
    sources/Mesh/VertexArray.cpp
    sources/Mesh/VertexBuffer.cpp
    sources/Registry/Registry.cpp
    sources/Registry/Keys.cpp
    sources/Scene/Scene.cpp
    sources/Scene/PlayScene.cpp
    sources/Shader/BasicShader.cpp
    sources/Shader/Shader.cpp
    sources/Shader/ShaderLoader.cpp
    sources/Shader/UniformLoader.cpp
    sources/Texture/Texture.cpp
    sources/Util/FileReader.cpp
    sources/Util/ImageLoader.cpp
    sources/World/World.cpp
    sources/Main.cpp
    sources/Application.cpp
    sources/Context.cpp
    sources/Camera.cpp
)

include(cmake/path_to_sdl2.cmake)

list(APPEND CMAKE_PREFIX_PATH ${SDL2_PATH})
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE})

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
