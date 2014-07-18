include_directories(${GLIB_INCLUDE_DIRS}
                    ${logics_SOURCE_DIR}/src)

SET(LIBSRC
    ${GLIB_LIBRARIES}
    logics)

SET(SRC_SYMBTEST
    symbtest.cc)
    
SET(SRC_LANGTEST
    langtest.cc)

SET(SRC_UNITEST
    unitest.cc)

ADD_EXECUTABLE(symbtest ${SRC_SYMBTEST})
TARGET_LINK_LIBRARIES(symbtest ${LIBSRC})
ADD_EXECUTABLE(langtest ${SRC_LANGTEST})
TARGET_LINK_LIBRARIES(langtest ${LIBSRC})
ADD_EXECUTABLE(unitest ${SRC_UNITEST})
TARGET_LINK_LIBRARIES(unitest ${LIBSRC})