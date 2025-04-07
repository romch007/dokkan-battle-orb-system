cmake_minimum_required(VERSION 3.28)
project(dokkan)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)

find_package(SFML 3 COMPONENTS Graphics REQUIRED)

include_directories(include)

add_executable(dokkan ${SOURCES} ${HEADERS})
target_link_libraries(dokkan PRIVATE SFML::Graphics)