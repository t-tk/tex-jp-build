
add_library(libkanji
  ptexdir/kanji.c
  ptexdir/kanji.h
  ptexdir/kanji_dump.c
  )

if(MSVC)
  target_compile_definitions(libkanji PRIVATE -D_CRT_SECURE_NO_WARNINGS=1)
endif()

target_include_directories(libkanji
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )

  target_link_libraries(libkanji ptexenc kpathsea zlib)

set(ptex_c_h
  ptexini.c
  ptex0.c
  ptexcoerce.h
  ptexd.h
  )

set(ptex_SRCS
  ${ptex_c_h}
  ptex-pool.c
  ptexdir/ptexextra.c
  ptexdir/ptexextra.h
  ptexdir/ptex_version.h
  )

if(WIN32)
  set(ptex dllptex)
  add_library(${ptex} SHARED ${ptex_SRCS})
else()
  set(ptex ptex)
  add_executable(${ptex} ${ptex_SRCS})
endif()

if(MSVC)
  target_compile_definitions(${ptex} PRIVATE -D_CRT_SECURE_NO_WARNINGS=1)
endif()

target_include_directories(${ptex}
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )

target_link_libraries(${ptex} libkanji web2c_libp ptexenc zlib web2c_lib kpathsea)

web2c_convert(ptex OUTPUT ${ptex_c_h} DEPENDS ptex.p ${web2c_texmf} ptexdir/ptex.defines)

web2c_texmf_tangle(ptex OUTPUT ptex.p ptex.pool DEPENDS ptex.web ptex.ch)

web2c_tie_m(ptex.web SOURCES tex.web tex.ch zlib-fmt.ch)
web2c_tie_c(ptex.ch SOURCES ptex.web ptexdir/ptex-base.ch tex-binpool.ch)

add_custom_command(
  OUTPUT ptex-pool.c
  DEPENDS ptex.pool ptexd.h makecpool
  COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/cmake/makecpool.py"
    "--makecpool" "$<TARGET_FILE_DIR:makecpool>/makecpool"
    ptex ptex-pool.c
  )

if(WIN32)
  foreach(e ptex)
    add_executable(${e} "cmake/calldll.c")
    target_compile_definitions(${e} PRIVATE DLLPROC=dllptexmain)
    target_link_libraries(${e} ${ptex})
  endforeach()
endif()
