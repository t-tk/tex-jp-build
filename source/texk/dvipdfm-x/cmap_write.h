/* This is dvipdfmx, an eXtended version of dvipdfm by Mark A. Wicks.

    Copyright (C) 2002-2015 by Jin-Hwan Cho and Shunsaku Hirata,
    the dvipdfmx project team.

    Copyright (C) 1998, 1999 by Mark A. Wicks <mwicks@kettering.edu>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
*/

#ifndef _CMAP_WRITE_H_
#define _CMAP_WRITE_H_

#include "cmap.h"

extern pdf_obj *CMap_create_stream (CMap *cmap);
#if 0
/* Not completed yet */
extern pdf_obj *CMap_ToCode_stream (CMap *cmap, const char *cmap_name,
				    CIDSysInfo *csi, int cmap_type,
				    unsigned char *used_slot, int flags);
#endif /* 0 */

#endif /*  _CMAP_WRITE_H_ */
