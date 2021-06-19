
set(eptex_c_h
  eptexini.c
  eptex0.c
  eptexcoerce.h
  eptexd.h
  )

set(eptex_SRCS
  ${eptex_c_h}
  eptex-pool.c
  eptexdir/eptexextra.c
  eptexdir/eptexextra.h
  eptexdir/eptex_version.h
  )

set(eptex_web_srcs
	tex.web
	etexdir/etex.ch
	etexdir/tex.ch0
	tex.ch
	tracingstacklevels.ch
	zlib-fmt.ch
	etexdir/tex.ech
  )

set(eptex_ch_srcs
  eptexdir/eptex-base.ch
  eptexdir/etex.ch0
  ptexdir/ptex-base.ch
  eptexdir/eptex.ech
  eptexdir/etex.ch1
  ${eptex_ch_synctex}
  eptexdir/fam256.ch
  eptexdir/pdfutils.ch
  eptexdir/char-warning-eptex.ch
  tex-binpool.ch
  )

if(WIN32)
  set(eptex dlleptex)
  add_library(${eptex} SHARED ${eptex_SRCS})
else()
  set(eptex eptex)
  add_executable(${eptex} ${eptex_SRCS})
endif()

if(MSVC)
  target_compile_definitions(${eptex} PRIVATE -D_CRT_SECURE_NO_WARNINGS=1)
endif()

target_include_directories(${eptex}
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/libmd5"
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )

target_link_libraries(${eptex} libkanji web2c_libp ptexenc libmd5 zlib web2c_lib kpathsea)

web2c_convert(eptex OUTPUT ${eptex_c_h} DEPENDS eptex.p ${web2c_texmf} eptexdir/eptex.defines)

web2c_texmf_tangle(eptex OUTPUT eptex.p eptex.pool DEPENDS eptex.web eptex.ch)

web2c_tie_m(eptex.web SOURCES ${eptex_web_srcs})
web2c_tie_c(eptex.ch SOURCES eptex.web ${eptex_ch_srcs})

add_custom_command(
  OUTPUT eptex-pool.c
  DEPENDS eptex.pool eptexd.h makecpool
  COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/cmake/makecpool.py"
    "--makecpool" "$<TARGET_FILE_DIR:makecpool>/makecpool"
    eptex eptex-pool.c
  )

if(WIN32)
  foreach(e eptex platex)
    add_executable(${e} "cmake/calldll.c")
    target_compile_definitions(${e} PRIVATE DLLPROC=dlleptexmain)
    target_link_libraries(${e} ${eptex})
  endforeach()
endif()
