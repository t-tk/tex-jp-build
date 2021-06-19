# CMakeLists.txt for texk/web2c/lib

set(web2c_lib_SRCS
  basechsuffix.c
  chartostring.c
  coredump.c
  eofeoln.c
  fprintreal.c
  inputint.c
  input2int.c
  lib.h
  main.c
  openclose.c
  printversion.c
  setupvar.c
  uexit.c
  usage.c
  version.c
  zround.c
  )

set(web2c_libp_SRCS
  openclose.c
  printversion.c
  )

add_library(web2c_lib STATIC ${web2c_lib_SRCS})
add_library(web2c_libp STATIC ${web2c_libp_SRCS})


target_compile_definitions(web2c_libp
  PRIVATE -DPTEX
  )

if(MSVC)
  target_compile_definitions(web2c_lib
    PRIVATE -D_CRT_SECURE_NO_WARNINGS=1
    )
  target_compile_definitions(web2c_libp
    PRIVATE -D_CRT_SECURE_NO_WARNINGS=1
    )
endif()

target_include_directories(web2c_lib
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/.."
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/.."
  )
target_include_directories(web2c_libp
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/.."
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/.."
  )

target_link_libraries(web2c_lib kpathsea)
target_link_libraries(web2c_libp kpathsea ptexenc)
