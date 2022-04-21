cmake_minimum_required(VERSION 3.16)
project(xcalc-rewrite CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp #include/core.cpp
        include/thunderengine.cpp)

#INCLUDE(FindPkgConfig)

#pkg_check_modules(SDL2 REQUIRED sdl2)
#pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

#include_directories(${SDL2_INCLUDE_DIRS}
        #${SDL2_TTF_INCLUDE_DIRS})

#link_directories (${SDL2_LIBRARY_DIRS}
        #${SDL2_TTF_LIBRARY_DIRS})

#target_link_libraries (${PROJECT_NAME}
        #${SDL2_LIBRARIES}
        #${SDL2_TTF_LIBRARIES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/Roboto-Regular.ttf ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
