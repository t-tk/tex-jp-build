

## libukanji.a for upTeX and e-upTeX

add_library(libukanji
  uptexdir/kanji.c
  uptexdir/kanji.h
  uptexdir/kanji_dump.c
  )

if(MSVC)
  target_compile_definitions(libukanji PRIVATE -D_CRT_SECURE_NO_WARNINGS=1)
endif()

target_include_directories(libukanji
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )

target_link_libraries(libukanji ptexenc kpathsea zlib)

# upTeX SyncTeX

set(uptex_include_synctex
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/synctexdir"
  )

set(uptex_link_synctex
  zlib
  )

set(uptex_ch_synctex
  synctexdir/synctex-def.ch0
  synctexdir/synctex-p-mem.ch0
  synctexdir/synctex-mem.ch0
  synctexdir/synctex-p-mem.ch1
  synctexdir/synctex-p-rec.ch0
  synctexdir/synctex-rec.ch0
  synctexdir/synctex-rec.ch1
  synctexdir/synctex-rec.ch2
  synctexdir/synctex-p-rec.ch1
  )

set(dist_uptex_SOURCES_synctex
  synctexdir/synctex.c
  synctexdir/synctex.h
  synctexdir/synctex-common.h
  synctexdir/synctex-uptex.h
  )

set(uptex_definitions_synctex
  PRIVATE -D__SyncTeX__
  PRIVATE -DSYNCTEX_ENGINE_H=\"synctex-uptex.h\"
  )

# upTeX

set(uptex_c_h
  uptexini.c
  uptex0.c
  uptexcoerce.h
  uptexd.h
  )

set(nodist_uptex_SOURCES
  ${uptex_c_h}
  uptex-pool.c
  )

set(dist_uptex_SOURCES
  uptexdir/uptexextra.c
  uptexdir/uptexextra.h
  uptexdir/uptex_version.h
  ${dist_uptex_SOURCES_synctex}
  )

set(uptex_web_srcs
  tex.web
  tex.ch
  tracingstacklevels.ch
  zlib-fmt.ch
  )

set(uptex_ch_srcs
  ptexdir/ptex-base.ch
  uptexdir/uptex-m.ch
  ${uptex_ch_synctex}
  tex-binpool.ch
  )

set(uptex_SRCS
  ${nodist_uptex_SOURCES}
  ${dist_uptex_SOURCES}
  )

if(WIN32)
  set(uptex dlluptex)
  add_library(${uptex} SHARED ${uptex_SRCS})
else()
  set(uptex uptex)
  add_executable(${uptex} ${uptex_SRCS})
endif()

if(MSVC)
  target_compile_definitions(${uptex} PRIVATE -D_CRT_SECURE_NO_WARNINGS=1 ${uptex_definitions_synctex})
endif()

target_include_directories(${uptex}
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  ${uptex_include_synctex}
  )

target_link_libraries(${uptex} libukanji web2c_libp ptexenc zlib web2c_lib kpathsea ${uptex_link_synctex})

web2c_convert(uptex OUTPUT ${uptex_c_h} DEPENDS uptex.p ${web2c_texmf} uptexdir/uptex.defines)

web2c_texmf_tangle(uptex OUTPUT uptex.p uptex.pool DEPENDS uptex.web uptex.ch)

web2c_tie_m(uptex.web SOURCES ${uptex_web_srcs})
web2c_tie_c(uptex.ch SOURCES uptex.web ${uptex_ch_srcs})

add_custom_command(
  OUTPUT uptex-pool.c
  DEPENDS uptex.pool uptexd.h makecpool
  COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/cmake/makecpool.py"
    "--makecpool" "$<TARGET_FILE_DIR:makecpool>/makecpool"
    uptex uptex-pool.c
  )

# Extract uptex version
add_custom_command(
  OUTPUT uptex_version.h
  DEPENDS uptex-m.ch
  COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/cmake/uptex_version.py"
    "-o" "${CMAKE_CURRENT_SOURCE_DIR}/uptexdir/uptex_version.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/uptexdir/uptex-m.ch"
  )


if(WIN32)
  foreach(e uptex)
    add_executable(${e} "cmake/calldll.c")
    target_compile_definitions(${e} PRIVATE DLLPROC=dlluptexmain)
    target_link_libraries(${e} ${uptex})
  endforeach()
endif()
