cmake_minimum_required(VERSION 3.22.1) # my version
project(dtcplus VERSION 0.0.0)

set(LINK_LIBS netc)
set(SRC_FILES 
  src/binary.cpp src/vls.cpp
  src/backend/dtc.cpp
  src/backend/dtcvls.cpp
  src/backend/dtc_extsc.cpp
)

include(GNUInstallDirs)

add_library(dtcplus SHARED ${SRC_FILES})
add_library(dtcplus::dtcplus ALIAS dtcplus)

target_link_libraries(dtcplus PRIVATE ${LINK_LIBS})

target_include_directories(
  dtcplus
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS dtcplus
  EXPORT dtcplusTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Include the CMakePackageConfigHelpers module
include(CMakePackageConfigHelpers)

# Set some properties for your library target
set_property(TARGET dtcplus PROPERTY VERSION ${PROJECT_VERSION})
set_property(TARGET dtcplus PROPERTY SOVERSION 1)
set_property(TARGET dtcplus PROPERTY
  INTERFACE_dtcplus_MAJOR_VERSION 1)
set_property(TARGET dtcplus APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING dtcplus_MAJOR_VERSION
)

# Generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/dtcplusConfigVersion.cmake"
  VERSION "${PROJECT_VERSION}"
  COMPATIBILITY AnyNewerVersion
)

# Create the config file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/dtcplusConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/dtcplusConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dtcplus
)

# Install the config and version files
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/dtcplusConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/dtcplusConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dtcplus
)

# Export the targets for the build tree
export(EXPORT dtcplusTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/dtcplusTargets.cmake"
  NAMESPACE dtcplus::
)

# Install the export set for the install tree
install(EXPORT dtcplusTargets
  FILE dtcplusTargets.cmake
  NAMESPACE dtcplus::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dtcplus
)


