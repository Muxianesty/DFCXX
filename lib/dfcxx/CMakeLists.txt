add_subdirectory(builders)
add_subdirectory(types)

set(SOURCES
        kernel.cpp
        ${BUILDERS_SOURCES}
        converter.cpp
)

add_library(DFCXX STATIC
        ${SOURCES}
)

target_include_directories(DFCXX
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/includeDev>
        )

## MLIRDFCIR has to be compiled beforehand.
target_link_libraries(DFCXX
        PUBLIC MLIRDFCIR
        PUBLIC CIRCTHW
        PUBLIC CIRCTSV
        PUBLIC CIRCTFIRRTLToHW
        PUBLIC CIRCTSeqToSV
        PUBLIC CIRCTExportVerilog)
add_dependencies(DFCXX MLIRDFCIR)