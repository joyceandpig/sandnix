/*
    Copyright 2016,王思远 <darknightghost.cn@gmail.com>

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

#pragma once

#include "../../../../../common/common.h"

#if defined X86
    #define	KERNEL_MEM_BASE		0xC0000000
    #define	KERNEL_MEM_SIZE		(1024 * 1024 * 1024)
    #ifndef	_ASM
        #include "./arch/x86/page_table.h"
    #endif

#elif defined ARM_ARMV7
    #define	KERNEL_MEM_BASE		0xC0000000
    #define	KERNEL_MEM_SIZE		(1024 * 1024 * 1024)
    #ifndef	_ASM
        #include "./arch/arm/armv7/page_table.h"
    #endif
#endif

#ifndef	_ASM

#define	MMU_PAGE_AVAIL			0x00000001
#define	MMU_PAGE_WRITABLE		0x00000002
#define	MMU_PAGE_EXECUTABLE		0x00000004
#define	MMU_PAGE_CACHEABLE		0x00000008

#define	MMU_PAGE_UNAVAIL		0x00000000
#define	MMU_PAGE_RDONLY			(MMU_PAGE_AVAIL | MMU_PAGE_CACHEABLE)
#define	MMU_PAGE_RW				(MMU_PAGE_AVAIL | MMU_PAGE_WRITABLE \
                                 | MMU_PAGE_CACHEABLE)
#define	MMU_PAGE_RDONLY_EXEC	(MMU_PAGE_AVAIL | MMU_PAGE_EXECUTABLE \
                                 | MMU_PAGE_CACHEABLE)
#define	MMU_PAGE_RW_EXEC		(MMU_PAGE_AVAIL | MMU_PAGE_WRITABLE \
                                 | MMU_PAGE_EXECUTABLE | MMU_PAGE_CACHEABLE)

#define	MMU_PAGE_RDONLY_NC		(MMU_PAGE_AVAIL)
#define	MMU_PAGE_RW_NC			(MMU_PAGE_AVAIL | MMU_PAGE_WRITABLE)
#define	MMU_PAGE_RDONLY_EXEC_NC	(MMU_PAGE_AVAIL | MMU_PAGE_EXECUTABL)
#define	MMU_PAGE_RW_EXEC_NC		(MMU_PAGE_AVAIL | MMU_PAGE_WRITABLE \
                                 | MMU_PAGE_EXECUTABLE)
#endif
