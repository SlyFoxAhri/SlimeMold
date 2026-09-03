cmake_minimum_required(VERSION 4.0)

project (SlimeMold)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND ON CACHE BOOL "" FORCE)
set(GLFW_BUILD_X11 OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE all_srcs
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/include/*.hpp
)

#set(SOURCES
#    ${PROJECT_SOURCE_DIR}/src/main.cpp
#)

add_executable(SlimeMold ${all_srcs})

target_include_directories(SlimeMold
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(SlimeMold
    PRIVATE
        raylib
)

