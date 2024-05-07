cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(DFCXX LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH "${CIRCT_BIN_HOME}")
list(APPEND CMAKE_PREFIX_PATH "${DFCIR_BUILD_DIR}")

## Needs to be used explicitly, because DFCIR doesn't (have to) export some libraries, needed in DFCXX.
find_package(DFCIR REQUIRED CONFIG)
find_package(CIRCT REQUIRED CONFIG)

add_subdirectory(include)
add_subdirectory(includeDev)
add_subdirectory(lib)

add_subdirectory(cmake)
