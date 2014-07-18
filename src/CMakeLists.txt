find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glibmm-2.4)
include_directories(${GLIB_INCLUDE_DIRS}
                    ${logics_SOURCE_DIR}/src)
#link_directories(${GLIB_LIBRARY_DIRS})

ADD_DEFINITIONS(-DUNICODE_FULLWIDTH)

SET(SRC
    logics.cc
    symbol.cc
    language.cc
    semantic.cc
    unicode.cc
    wff.cc
)

SET(LIBSRC
    ${GLIB_LIBRARIES}
)

ADD_LIBRARY(logics ${SRC})
TARGET_LINK_LIBRARIES(logics ${LIBSRC})
