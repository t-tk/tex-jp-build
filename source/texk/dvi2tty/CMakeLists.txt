# CMakeLists.txt for dvi2tty directory

include(cmake/config.cmake)

get_property(KPATHSEA_INCLUDES GLOBAL PROPERTY KPATHSEA_INCLUDES)

include_directories(${KPATHSEA_INCLUDES})

set(SRC dvi2tty-src)

set(disdvi_SOURCES
  ${SRC}/commands.h
  ${SRC}/disdvi.c
  )
set(dvi2tty_SOURCES
  ${SRC}/commands.h
  ${SRC}/dvi2tty.c
  ${SRC}/dvi2tty.h
  ${SRC}/tex2ucs.h
  ${SRC}/dvistuff.c
  )

add_executable(disdvi ${disdvi_SOURCES})
add_executable(dvi2tty ${dvi2tty_SOURCES})

target_include_directories(disdvi
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
  PUBLIC "${CMAKE_CURRENT_BINARY_DIR}"
  )
target_include_directories(dvi2tty
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
  PUBLIC "${CMAKE_CURRENT_BINARY_DIR}"
  )

target_link_libraries(disdvi kpathsea)
target_link_libraries(dvi2tty kpathsea ptexenc)
