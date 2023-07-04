# CMakeLists.txt for seetexk directory

include(cmake/config.cmake)

get_property(KPATHSEA_INCLUDES GLOBAL PROPERTY KPATHSEA_INCLUDES)

include_directories(${KPATHSEA_INCLUDES})

set(seetex_SOURCES
  dviclass.c
  dviclass.h
  error.c
  error.h
  fio.c
  fio.h
  font.h
  gripes.h
  gripes0.c
  gripes1.c
  search.c
  search.h
  seek.h
  seek.c
  tempfile.c
  tempfile.h
  types.h
  common.h
  )
set(dvibook_SOURCES
  dvibook.c
  config.h
  )
set(dviconcat_SOURCES
  dviconcat.c
  config.h
  )
set(dviselect_SOURCES
  dviselect.c
  config.h
  )
set(dvitodvi_SOURCES
  dvitodvi.c
  config.h
  )

add_library(seetex STATIC ${seetex_SOURCES})
target_compile_definitions(seetex PUBLIC -DKPATHSEA -DHAVE_STRERROR)
target_include_directories(seetex
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  PUBLIC "${KPATHSEA_INCLUDES}"
  )
set_target_properties(seetex PROPERTIES OUTPUT_NAME "seetex")

add_executable(dvibook ${dvibook_SOURCES})
add_executable(dviconcat ${dviconcat_SOURCES})
add_executable(dviselect ${dviselect_SOURCES})
add_executable(dvitodvi ${dvitodvi_SOURCES})

target_compile_definitions(dvibook
  PUBLIC -DKPATHSEA -DHAVE_CONFIG_H
  )
target_compile_definitions(dviconcat
  PUBLIC -DKPATHSEA -DHAVE_CONFIG_H
  )
target_compile_definitions(dviselect
  PUBLIC -DKPATHSEA -DHAVE_CONFIG_H
  )
target_compile_definitions(dvitodvi
  PUBLIC -DKPATHSEA -DHAVE_CONFIG_H
  )

target_include_directories(dvibook
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )
target_include_directories(dviconcat
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )
target_include_directories(dviselect
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )
target_include_directories(dvitodvi
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )

target_link_libraries(seetex kpathsea)

target_link_libraries(dvibook kpathsea seetex)
target_link_libraries(dviconcat kpathsea seetex)
target_link_libraries(dviselect kpathsea seetex)
target_link_libraries(dvitodvi kpathsea seetex)
