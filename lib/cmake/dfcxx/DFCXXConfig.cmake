# Compute the installation prefix from this DFCXXConfig.cmake file location.
get_filename_component(DFCXX_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(DFCXX_INSTALL_PREFIX "${DFCXX_INSTALL_PREFIX}" PATH)
get_filename_component(DFCXX_INSTALL_PREFIX "${DFCXX_INSTALL_PREFIX}" PATH)
get_filename_component(DFCXX_INSTALL_PREFIX "${DFCXX_INSTALL_PREFIX}" PATH)

message(STATUS ${DFCXX_INSTALL_PREFIX})

set(DFCXX_EXPORTED_TARGETS "DFCXX")
set(DFCXX_CMAKE_DIR "${CIRCT_INSTALL_PREFIX}/lib/cmake/dfcxx")
set(DFCXX_BINARY_DIR "${CIRCT_INSTALL_PREFIX}")
set(DFCXX_INCLUDE_DIRS "${CIRCT_INSTALL_PREFIX}/include")
set(DFCXX_LIBRARY_DIRS "${CIRCT_INSTALL_PREFIX}/lib")
