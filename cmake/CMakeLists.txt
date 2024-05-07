set(DFCXX_PACKAGE_DIR lib/cmake/DFCXX)

export(TARGETS DFCXX
       NAMESPACE DFCXX::
       FILE ${CMAKE_BINARY_DIR}/${DFCXX_PACKAGE_DIR}/DFCXXTargets.cmake
       )

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/DFCXXConfig.cmake.in
        ${CMAKE_BINARY_DIR}/${DFCXX_PACKAGE_DIR}/DFCXXConfig.cmake
        @ONLY
        )
