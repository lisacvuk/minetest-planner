cmake_minimum_required (VERSION 2.6)
project (App)
add_executable(App src/main.cpp src/app.cpp src/tile.cpp src/camera.cpp)
target_link_libraries(App SDL2)
