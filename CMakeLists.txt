cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(DFCXX LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(DFCIR)

list(APPEND CMAKE_PREFIX_PATH "${CIRCT_BIN_HOME}")
find_package(CIRCT REQUIRED CONFIG)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/includeDev)

add_subdirectory(include)
add_subdirectory(includeDev)
add_subdirectory(lib)

##add_executable(TEST test.cpp)
##target_link_libraries(TEST DFCXX)