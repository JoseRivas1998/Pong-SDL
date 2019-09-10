cmake_minimum_required(VERSION 3.7)

project(Pong)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/graphics/Graphics.hpp src/app/LichPP.cpp src/app/LichPP.hpp src/app/ApplicationConfiguration.hpp src/graphics/Graphics.cpp src/app/App.cpp src/app/App.hpp src/gamestates/States.hpp src/managers/GameStateManager.cpp src/managers/GameStateManager.hpp src/gamestates/GameState.hpp src/gamestates/PlayState.cpp src/gamestates/PlayState.hpp src/math/Rectangle.cpp src/math/Rectangle.hpp)
add_executable(Pong ${SOURCE_FILES})

target_link_libraries(Pong ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

