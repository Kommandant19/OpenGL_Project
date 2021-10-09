Cmake_minimum_required(VERSION 3.20)
project(OpenGL)

set(CMAKE_CXX_STANDARD 17)


include_directories(Deps/GLFW)
include_directories(Deps/GLFW/include)
include_directories(Deps/GLFW/include/GLFW)

include_directories(Deps/glad)
include_directories(Deps/glad/Source/glad.c)


add_subdirectory(Deps/glad)
add_subdirectory(Deps/glfw)

add_executable(OpenGL
        Engine/Source/IndexBuffer.cpp
        Engine/Source/IndexBuffer.h
        Engine/Source/Main.cpp
        Engine/Source/Shader.cpp
        Engine/Source/Shader.h
        Engine/Source/VertexArray.cpp
        Engine/Source/VertexArray.h
        Engine/Source/VertexBuffer.cpp
        Engine/Source/VertexBuffer.h
)

target_precompile_headers(OpenGL PRIVATE "Engine/Source/PCH.h")

target_link_libraries(OpenGL
        PRIVATE glfw
        PRIVATE glad
)