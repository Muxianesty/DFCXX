add_subdirectory(IRbuilders)
add_subdirectory(types)

set(SOURCES
        kernel.cpp
        ${IR_BUILDERS_SOURCES}
        ${TYPES_SOURCES}
        ${VAR_BUILDERS_SOURCES}
        ${TYPE_BUILDERS_SOURCES}
        converter.cpp
        var.cpp
        kernstorage.cpp
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