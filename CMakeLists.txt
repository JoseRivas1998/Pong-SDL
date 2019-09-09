cmake_minimum_required(VERSION 3.7)

project(Pong)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp)

add_executable(Pong ${SOURCE_FILES})
target_link_libraries(Pong ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

