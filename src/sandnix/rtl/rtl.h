/*
	Copyright 2015,暗夜幽灵 <darknightghost.cn@gmail.com>

	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef	RTL_H_INCLUDE
#define	RTL_H_INCLUDE

#ifdef	X86
#include "../../common/arch/x86/types.h"
//Variable Arguments
typedef	char*			va_list;

#define	va_start(ap,v)	((ap) = (va_list)&(v) + 4)

#define	va_arg(ap,t)	(ap += 4 ,(\
                                   sizeof(t) <= 4\
                                   ? *((t*)(ap-4))\
                                   : **((t**)(ap-4))))

#define	va_end(ap)		(ap = (va_list)0)
#endif	//!	X86

#include "list/list.h"
#include "string/string.h"
#include "math/math.h"

#endif	//!	RTL_H_INCLUDE
