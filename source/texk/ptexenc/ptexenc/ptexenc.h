/*
 *  KANJI Code conversion routines.
 */

#ifndef PTEXENC_PTEXENC_H
#define PTEXENC_PTEXENC_H

#include <kpathsea/types.h>

#if defined (WIN32) && !defined (__MINGW32__) && !defined (NO_PTENC_DLL)
#define PTENC_DLL 1
#endif /* WIN32 && !__MINGW32__ && !NO_PTENC_DLL */

#if defined (PTENC_DLL) && (defined (WIN32) || defined (__CYGWIN__))
#ifdef MAKE_PTENC_DLL
#define PTENCDLL __declspec(dllexport)
#else /* ! MAKE_PTENC_DLL */
#define PTENCDLL __declspec(dllimport)
#endif
#else /* ! (PTENC_DLL && (WIN32 || __CYGWIN__)) */
#define PTENCDLL
#endif

extern PTENCDLL const char *ptexenc_version_string;
#if defined(WIN32)
extern PTENCDLL int sjisterminal;
extern PTENCDLL int infile_enc_auto;
#endif

#define KANJI_OPTS "{jis|euc|sjis|utf8}"

/* enable/disable UPTEX */
extern PTENCDLL void enable_UPTEX (boolean enable);

/* get/set Kanji encoding by string */
extern PTENCDLL const_string get_enc_string(void);
extern PTENCDLL int    set_enc_string(const_string file, const_string inter);
#define getencstring  get_enc_string
#define setencstring  set_enc_string

/* decide if internal Kanji encode is SJIS or not */
extern PTENCDLL boolean  is_internalSJIS(void);
#define isinternalSJIS  is_internalSJIS

/* check char range */
extern PTENCDLL boolean iskanji1(int c);
extern PTENCDLL boolean iskanji2(int c);

/* internal (EUC/SJIS) from/to buffer (EUC/SJIS/UTF-8) code conversion */
extern PTENCDLL int multistrlen(string s, int len, int pos);
extern PTENCDLL long fromBUFF(string s, int len, int pos);
extern PTENCDLL long toBUFF(long inter);

/* internal (EUC/SJIS) from/to DVI (JIS) code conversion */
#define fromDVI fromJIS
#define toDVI   toJIS

/* JIS/EUC/SJIS/KUTN/UCS to internal (EUC/SJIS) code conversion */
/* (only for \euc primitive, etc.) */
extern PTENCDLL long toJIS(long kcode);
extern PTENCDLL long fromJIS(long jis);
extern PTENCDLL long fromEUC(long euc);
extern PTENCDLL long fromSJIS(long sjis);
extern PTENCDLL long fromKUTEN(long kuten);
extern PTENCDLL long fromUCS (long ucs);
extern PTENCDLL long toUCS(long kcode);

/* fputs/putc with encoding conversion */
extern PTENCDLL int putc2(int c, FILE *fp);
extern PTENCDLL int fputs2(const char *s, FILE *fp);

/* input line with encoding conversion */
extern PTENCDLL long input_line2(FILE *fp, string buff, long pos,
				const long buffsize, int *lastchar);

/* open/close through nkf */
extern PTENCDLL void nkf_disable(void);
extern PTENCDLL FILE *nkf_open(const char *path, const char *mode);
extern PTENCDLL int nkf_close(FILE *fp);

#endif /* PTEXENC_PTEXENC_H */
