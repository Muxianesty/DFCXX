add_subdirectory(IRbuilders)
add_subdirectory(types)
add_subdirectory(typebuilders)
add_subdirectory(vars)
add_subdirectory(varbuilders)

set(SOURCES
        kernel.cpp
        ${IR_BUILDERS_SOURCES}
        ${TYPES_SOURCES}
        ${VARS_SOURCES}
        ${VAR_BUILDERS_SOURCES}
        ${TYPE_BUILDERS_SOURCES}
        converter.cpp
        kernstorage.cpp
        io.cpp
        offset.cpp
        constant.cpp
        control.cpp
        graph.cpp
        node.cpp
        channel.cpp
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

## MLIRDFCIR is ensured to be compiled beforehand.
target_link_libraries(DFCXX
        PRIVATE $<LINK_ONLY:DFCIR::MLIRDFCIR>
        PRIVATE $<LINK_ONLY:CIRCTHW>
        PRIVATE $<LINK_ONLY:CIRCTSV>
        PRIVATE $<LINK_ONLY:CIRCTFIRRTLToHW>
        PRIVATE $<LINK_ONLY:CIRCTSeqToSV>
        PRIVATE $<LINK_ONLY:CIRCTExportVerilog>
        )


add_library(DFCXX::DFCXX ALIAS DFCXX)
