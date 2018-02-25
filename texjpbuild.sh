#!/bin/sh -x

# making working directory to build targets.
cd source && mkdir -p Work && cd Work

########################################
# configure && make && make install, and run tests
# on build source top directory.
# in web2c, we only make:
# (e|u)ptex, (u)pmpost, cweave, tie, and (c)tangle.
# [TODO] How to build omegaware and omegafonts?
../Build \
  --disable-all-pkgs \
  --enable-debug \
  --enable-dvi2tty \
  --enable-dvipdfm-x \
  --enable-dvipsk \
  --enable-makejvf \
  --enable-mendexk \
  --enable-upmendex \
  --enable-dvidvi \
  --enable-seetexk \
  --enable-web2c \
  --enable-ptex \
  --enable-eptex \
  --enable-uptex \
  --enable-euptex \
  --enable-pmp \
  --enable-upmp \
  --disable-web-progs \
  --disable-tex \
  --disable-mf \
  --disable-mflua \
  --disable-mfluajit \
  --disable-mp \
  --disable-pdftex \
  --disable-luatex \
  --disable-luatex53 \
  --disable-luajittex \
  --disable-xetex \
  --disable-aleph \
  --without-mf-x-toolkit \
  --with-gnu-ld \
  --without-x \
  --without-system-kpathsea \
  --without-system-ptexenc \
  --without-system-zlib \
  --without-system-libpaper \
  --without-system-libpng \
  --without-system-freetype2 \
  --without-system-gd \
  --without-system-pixman \
  --without-system-cairo \
  --without-system-gmp \
  --without-system-mpfr \
  --without-system-poppler \
  --without-system-xpdf \
  --without-system-zziplib \
  --without-system-graphite2 \
  --without-system-teckit \
  --without-system-icu \
  --without-system-harfbuzz \
  --disable-xpdfopen \
  CFLAGS=-g CXXFLAGS=-g
