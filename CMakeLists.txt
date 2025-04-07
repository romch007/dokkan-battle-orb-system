cmake_minimum_required(VERSION 3.30)
project(dokkan LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)

find_package(SFML 3 COMPONENTS Graphics REQUIRED)

include_directories(include)

add_executable(dokkan WIN32 ${SOURCES} ${HEADERS})
target_link_libraries(dokkan PRIVATE SFML::Graphics)

install(TARGETS dokkan
	RUNTIME_DEPENDENCIES
    PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
    POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
)