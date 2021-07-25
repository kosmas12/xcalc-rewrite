cmake_minimum_required(VERSION 3.16)
project(xcalc-rewrite CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
