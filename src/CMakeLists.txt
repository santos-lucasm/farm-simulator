cmake_minimum_required(VERSION 3.16)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(player player.c)
add_library(camera camera.c)
add_library(world world.c tile.c)
