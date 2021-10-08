Cmake_minimum_required(VERSION 3.20)
project(OpenGL)

set(CMAKE_CXX_STANDARD 17)


include_directories(Deps/glfw/GLFW/include)
include_directories(Deps/glfw/include/include/GLFW)
include_directories(Deps/glfw/GLFW)
include_directories(Engine/src/Main.cpp)


add_subdirectory(Deps/glad)
add_subdirectory(Deps/glfw)

add_executable(OpenGL
        Engine/src/Main.cpp
)

target_precompile_headers  (OpenGL PRIVATE "Engine/src/PCH.h")