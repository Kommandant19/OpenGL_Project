Cmake_minimum_required(VERSION 3.20)
project(OpenGL)

set(CMAKE_CXX_STANDARD 17)


include_directories(Deps/GLFW/include)
include_directories(Deps/GLFW/include/GLFW)
include_directories(Deps/GLFW)
include_directories(Deps/glad)

add_subdirectory(Deps/glad)
add_subdirectory(Deps/glfw)

add_executable(OpenGL
        Engine/src/Main.cpp
)

target_precompile_headers(OpenGL PRIVATE "Engine/src/PCH.h")

target_link_libraries( OpenGL
        PRIVATE glfw
        PRIVATE glad
)