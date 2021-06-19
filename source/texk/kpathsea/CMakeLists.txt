# CMakeLists.txt for kpathsea

set(kpathsea_VERSION "6.3.4/dev")

option(NO_KPSE_DLL "NO_KPSE_DLL" OFF)
option(MAKE_OMEGA_OCP_BY_DEFAULT "Run mkocp if OCP file is missing." OFF)
option(MAKE_OMEGA_OFM_BY_DEFAULT "Run mkofm if OFM file is missing." OFF)
option(MAKE_TEX_FMT_BY_DEFAULT "Run mktexfmt if format file is missing." OFF)
option(MAKE_TEX_MF_BY_DEFAULT "Run mktexmf if MF source is missing." OFF)
option(MAKE_TEX_PK_BY_DEFAULT "Run mktexpk if PK font is missing." OFF)
option(MAKE_TEX_TEX_BY_DEFAULT "Run mktextex if TeX source is missing." OFF)
option(MAKE_TEX_TFM_BY_DEFAULT "Run mktextfm if TFM file is missing." OFF)

if(MSVC)
  set(HAVE_DIRENT_H 1)
  set(HAVE_GETCWD 1)

  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/dirent.h"
    "${CMAKE_CURRENT_BINARY_DIR}/dirent.h"
    COPYONLY
    )

  set(kpathsea_SRCS
    ${kpathsea_SRCS}
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/dirent.c"
    )
endif()

include(CheckIncludeFile)

check_include_file(assert.h HAVE_ASSERT_H)
check_include_file(dirent.h HAVE_DIRENT_H)
check_include_file(float.h HAVE_FLOAT_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)
check_include_file(libintl.h HAVE_LIBINTL_H)
check_include_file(limits.h HAVE_LIMITS_H)
check_include_file(memory.h HAVE_MEMORY_H)
check_include_file(ndir.h HAVE_NDIR_H)
check_include_file(pwd.h HAVE_PWD_H)
check_include_file(stdint.h HAVE_STDINT_H)
check_include_file(stdlib.h HAVE_STDLIB_H)
check_include_file(strings.h HAVE_STRINGS_H)
check_include_file(string.h HAVE_STRING_H)
check_include_file(sys/dir.h HAVE_SYS_DIR_H)
check_include_file(sys/ndir.h HAVE_SYS_NDIR_H)
check_include_file(sys/param.h HAVE_SYS_PARAM_H)
check_include_file(unistd.h HAVE_UNISTD_H)

include(CheckSymbolExists)

check_symbol_exists(getcwd "unistd.h" HAVE_GETCWD)
check_symbol_exists(getwd "unistd.h" HAVE_GETWD)
check_symbol_exists(memcmp "string.h" HAVE_MEMCMP)
check_symbol_exists(memcpy "string.h" HAVE_MEMCPY)
check_symbol_exists(strchr "string.h" HAVE_STRCHR)
check_symbol_exists(strrchr "string.h" HAVE_STRRCHR)

check_symbol_exists(isascii "ctype.h" HAVE_DECL_ISASCII)
check_symbol_exists(putenv "stdlib.h" HAVE_DECL_PUTENV)

include(CheckIncludeFiles)

check_include_files("stdlib.h;stdarg.h;string.h;float.h" STDC_HEADERS)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/c-auto.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/c-auto.h"
  @ONLY
  )

set(kpathsea_SRCS ${kpathsea_SRCS}
  tex-file.c
  absolute.c
  atou.c
  cnf.c
  concat.c
  concat3.c
  concatn.c
  db.c
  debug.c
  dir.c
  elt-dirs.c
  expand.c
  extend-fname.c
  file-p.c
  find-suffix.c
  fn.c
  fontmap.c
  hash.c
  kdefault.c
  kpathsea.c
  line.c
  magstep.c
  make-suffix.c
  path-elt.c
  pathsearch.c
  proginit.c
  progname.c
  readable.c
  rm-suffix.c
  str-list.c
  str-llist.c
  tex-glyph.c
  tex-hush.c
  tex-make.c
  tilde.c
  uppercasify.c
  variable.c
  version.c
  xbasename.c
  xcalloc.c
  xdirname.c
  xfopen.c
  xfseek.c
  xftell.c
  xgetcwd.c
  xmalloc.c
  xopendir.c
  xputenv.c
  xrealloc.c
  xstat.c
  xstrdup.c
  )

if(NOT MINGW32)
  set(kpathsea_SRCS ${kpathsea_SRCS}
    getopt.c
    getopt1.c
    )
endif()

if(WIN32)
  if(MINGW32)
    set(kpathsea_SRCS ${kpathsea_SRCS}
      mingw32.c
      xfseeko.c
      xftello.c
      )
  else()
    set(kpathsea_SRCS ${kpathsea_SRCS}
      win32lib.c
      )
  endif()

  set(kpathsea_SRCS ${kpathsea_SRCS}
    knj.c
    )
else()
  set(kpathsea_SRCS ${kpathsea_SRCS}
    xfseeko.c
    xftello.c
    )
endif()

set(kpathsea_HDRS
  c-auto.h
  kpathsea.h
  paths.h
  )

# Headers included directly into kpathsea.h
set(kpathsea_direct_headers
  absolute.h
  c-dir.h
  c-fopen.h
  c-namemx.h
  c-pathch.h
  c-pathmx.h
  c-stat.h
  cnf.h
  concatn.h
  expand.h
  getopt.h
  line.h
  magstep.h
  pathsearch.h
  proginit.h
  readable.h
  tex-glyph.h
  tex-hush.h
  tex-make.h
  variable.h
  version.h
  )

set(kpathsea_HDRS ${kpathsea_HDRS} ${kpathsea_direct_headers})

set(kpathsea_HDRS ${kpathsea_HDRS}
  c-ctype.h
  c-errno.h
  c-limits.h
  c-memstr.h
  c-minmax.h
  c-proto.h
  c-std.h
  c-unistd.h
  debug.h
  hash.h
  knj.h
  lib.h
  mingw32.h
  progname.h
  simpletypes.h
  str-list.h
  str-llist.h
  systypes.h
  tex-file.h
  types.h
  win32lib.h
  )

set(kpathsea_HDRS ${kpathsea_HDRS} config.h)

set(kpathsea_SRCS ${kpathsea_SRCS} ${kpathsea_HDRS})

if(NO_KPSE_DLL)
  add_library(kpathsea STATIC ${kpathsea_SRCS})
  target_compile_definitions(kpathsea PUBLIC NO_KPSE_DLL)
else()
  add_library(kpathsea SHARED ${kpathsea_SRCS})
endif()

target_compile_definitions(kpathsea
  PRIVATE -DMAKE_KPSE_DLL
  PRIVATE -D_CRT_SECURE_NO_WARNINGS=1
  )

target_include_directories(kpathsea
  PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/.."
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/.."
  )

add_custom_command(
  OUTPUT paths.h
  DEPENDS texmf.cnf cmake/cnf-to-paths.py
  COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cnf-to-paths.py"
    "${CMAKE_CURRENT_SOURCE_DIR}/texmf.cnf"
    "${CMAKE_CURRENT_BINARY_DIR}/paths.h"
  )

add_custom_command(
  OUTPUT kpathsea.h
  DEPENDS cmake/kpathsea.py
  COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/cmake/kpathsea.py"
    "${CMAKE_CURRENT_BINARY_DIR}/kpathsea.h"
    config.h paths.h ${kpathsea_direct_headers}
  )

if(WIN32)
  add_subdirectory(win32)
endif()
