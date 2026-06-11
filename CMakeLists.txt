cmake_minimum_required(VERSION 3.25)
project(sl_to_text LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED COMPONENTS core videoio highgui)

add_executable(sl_to_text
    src/main.cpp
    src/inference/video-capture.cpp
)

target_include_directories(sl_to_text PRIVATE
    src
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(sl_to_text PRIVATE
    opencv_core
    opencv_videoio
    opencv_highgui
)
