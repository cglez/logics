cmake_minimum_required (VERSION 2.8)
project (logics)

# The version number
set (logics_VERSION_MAJOR 0)
set (logics_VERSION_MINOR 1)

OPTION( BUILD_SHARED_LIBS "Set to OFF to build static libraries" ON )
OPTION( INSTALL_DOC "Set to OFF to skip build/install Documentation" OFF )

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

add_subdirectory (src)
add_subdirectory (tests)
