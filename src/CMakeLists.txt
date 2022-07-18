cmake_minimum_required(VERSION 3.16)

include_directories(${PROJECT_SOURCE_DIR}/include/)

add_executable(farm-sim main.c)

target_link_libraries(farm-sim
   player camera
   libraylib.so
)
