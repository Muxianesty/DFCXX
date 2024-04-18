add_subdirectory(builders)
add_subdirectory(types)

set(SOURCES
        kernel.cpp
        ${BUILDERS_SOURCES}
)

add_library(DFCXX STATIC
        ${SOURCES}
)

target_include_directories(DFCXX
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

## MLIRDFCIR has to be compiled beforehand.
target_link_libraries(DFCXX PUBLIC MLIRDFCIR)
add_dependencies(DFCXX MLIRDFCIR)