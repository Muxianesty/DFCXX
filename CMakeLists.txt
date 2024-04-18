cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(DFCXX LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(DFCIR)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(include)
add_subdirectory(lib)
