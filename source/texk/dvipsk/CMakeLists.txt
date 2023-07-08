# CMakeLists.txt for dvips

set(VERSION "2023.1")

include(cmake/config.cmake)

get_property(KPATHSEA_INCLUDES GLOBAL PROPERTY KPATHSEA_INCLUDES)

include_directories(${KPATHSEA_INCLUDES})

set(afm2tfm_SOURCES
  afm2tfm.c
  )
set(dvips_SOURCES
  bbox.c
  bitmapenc.c
  color.c
  config.h
  debug.h
  dopage.c
  dosection.c
  dospecial.c
  download.c
  dpicheck.c
  drawPS.c
  dviinput.c
  dvips.c
  dvips.h
  emspecial.c
  finclude.c
  fontdef.c
  header.c
  hps.c
  loadfont.c
  output.c
  papersiz.c
  paths.h
  pprescan.c
  prescan.c
  protos.h
  protos_add.h
  ptexmac.h
  repack.c
  resident.c
  scalewidth.c
  scanpage.c
  search.c
  skippage.c
  t1part.c
  t1part.h
  tfmload.c
  unpack.c
  virtualfont.c
  writet1.c
  )

set(dvips_SOURCES ${dvips_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/c-auto.h)

  add_library(dvips SHARED ${dvips_SOURCES})
  set_target_properties(dvips PROPERTIES OUTPUT_NAME "dvips")
# add_executable(dvips ${dvips_SOURCES})

target_compile_definitions(dvips
  PRIVATE -DKPATHSEA
  PRIVATE -DHAVE_CONFIG_H=1
  PRIVATE -DHAVE_LIBPNG
  PRIVATE -DHAVE_ZLIB
  PRIVATE -DHAVE_ZLIB_COMPRESS2
  )


target_include_directories(dvips
  PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
  )

target_link_libraries(dvips kpathsea)

  add_executable(calldll_dvips "cmake/calldll.c")
  target_compile_definitions(calldll_dvips PRIVATE DLLPROC=dlldvipsmain)
  target_link_libraries(calldll_dvips dvips)

    add_custom_command(TARGET calldll_dvips POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
        "$<TARGET_FILE_DIR:calldll_dvips>/calldll_dvips.exe"
        "$<TARGET_FILE_DIR:calldll_dvips>/dvips.exe"
      )

