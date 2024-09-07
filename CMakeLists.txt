cmake_minimum_required(VERSION 3.14)

project(
    video_3
    VERSION 0.0.0
    DESCRIPTION "Game snake"
    LANGUAGES CXX
)

set(CMAKE_BUILD_TYPE  Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(sources
    src/Game_snake.h 
    src/Game_snake.cpp
    src/Paint.h
    src/Paint.cpp
    src/main.cpp
)

find_package(Qt5 COMPONENTS Core REQUIRED_FILES)

find_package(Qt5 COMPONENTS Widgets REQUIRED_FILES)

add_executable(Snake ${sources})

target_link_libraries(Snake PRIVATE Qt5::Core Qt5::Widgets ${LINK_FLAGS} )




