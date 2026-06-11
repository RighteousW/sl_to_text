# SL to Text

This project is made with the intention of translating Malawi sign-language to text(English and Chichewa).

We'll start of small:
- first numbers, 
- then alphanumeric characters, 
- then common simple gestures, 
- then common complex gestures,
- then adding as needed.

Since our main source of ground truth is the 
1. Malawian Sign Language dictionary: https://malawi.mediapalo.fi/material/pdf/msld.pdf
2. a playlist of videos: https://www.youtube.com/playlist?list=PLH-lQKvccYLG13-hiLvpTMxMEBAXEjyvw

we will have certain hurdles that will come to light as we go on.


## Requirements
- C++23 compiler
- CMake
- GLFW
- OpenGL/Mesa

On Arch Linux:
    sudo pacman -S cmake gcc glfw-x11 mesa


## Build
    cmake -S . -B dist
    cmake --build dist

## Run
    ./dist/sl_to_text
