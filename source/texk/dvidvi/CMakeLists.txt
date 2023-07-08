# CMakeLists.txt for dvidvi directory

include(cmake/config.cmake)

get_property(KPATHSEA_INCLUDES GLOBAL PROPERTY KPATHSEA_INCLUDES)

set(dvidvi_SOURCES
  dvidvi.c
  config.h
  )

add_executable(dvidvi ${dvidvi_SOURCES})

target_include_directories(dvidvi
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )

target_compile_definitions(dvidvi PRIVATE -DKPATHSEA -DHAVE_CONFIG_H)

target_link_libraries(dvidvi kpathsea)
