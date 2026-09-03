cmake_minimum_required(VERSION 3.3...4.4)

project (SlimeMold)

option(BUILD_NORMAL "Build normaly" ON)
option(BUILD_TESTING "Build tests" OFF)
option(RAYLIB_FETCH "Download raylib if not installed" ON)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

if (NOT raylib_FOUND AND RAYLIB_FETCH)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
        FetchContent_MakeAvailable(raylib)
    )
endif()

file(GLOB_RECURSE all_srcs
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/include/*.hpp
)

add_executable(SlimeMold ${all_srcs})

target_include_directories(SlimeMold
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(SlimeMold
    PRIVATE
        raylib
)

