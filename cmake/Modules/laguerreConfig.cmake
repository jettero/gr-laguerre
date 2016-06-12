INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_LAGUERRE laguerre)

FIND_PATH(
    LAGUERRE_INCLUDE_DIRS
    NAMES laguerre/api.h
    HINTS $ENV{LAGUERRE_DIR}/include
        ${PC_LAGUERRE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    LAGUERRE_LIBRARIES
    NAMES gnuradio-laguerre
    HINTS $ENV{LAGUERRE_DIR}/lib
        ${PC_LAGUERRE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LAGUERRE DEFAULT_MSG LAGUERRE_LIBRARIES LAGUERRE_INCLUDE_DIRS)
MARK_AS_ADVANCED(LAGUERRE_LIBRARIES LAGUERRE_INCLUDE_DIRS)

