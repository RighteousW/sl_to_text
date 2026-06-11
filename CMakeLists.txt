cmake_minimum_required(VERSION 3.25)
project(sl_to_text LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(sl_to_text
    src/main.cpp
    src/gui/window.cpp
)

target_include_directories(sl_to_text PRIVATE
    src
)

target_link_libraries(sl_to_text PRIVATE
    glfw
    OpenGL::GL
)
