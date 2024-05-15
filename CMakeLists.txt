cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(DFCXX LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

if(DEFINED CIRCT_BIN_HOME)
    message(STATUS "CIRCT_BIN_HOME: ${CIRCT_BIN_HOME}")
    list(APPEND CMAKE_PREFIX_PATH "${CIRCT_BIN_HOME}")
else()
    message(FATAL_ERROR "CIRCT_BIN_HOME var is not set!")
endif()

if(DEFINED DFCIR_BUILD_DIR)
    message(STATUS "DFCIR_BUILD_DIR: ${DFCIR_BUILD_DIR}")
    list(APPEND CMAKE_PREFIX_PATH "${DFCIR_BUILD_DIR}")
else()
    message(FATAL_ERROR "DFCIR_BUILD_DIR var is not set!")
endif()

## Needs to be used explicitly, because DFCIR doesn't (have to) export some libraries, needed in DFCXX.
find_package(DFCIR REQUIRED CONFIG)
find_package(CIRCT REQUIRED CONFIG)

add_subdirectory(include)
add_subdirectory(includeDev)
add_subdirectory(lib)

add_subdirectory(examples)

add_subdirectory(cmake)
