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
#define	HAL_INIT_EXPORT

#include "../../../../common/common.h"

#if defined X86
    #define	DEFAULT_STACK_SIZE		(12 * 4096)
    #define KERNEL_HEADER_MAGIC		0x444E4153
    #include "./arch/x86/init_defs.h"
#elif defined ARM
    #define	DEFAULT_STACK_SIZE		(12 * 4096)
    #define KERNEL_HEADER_MAGIC		0x444E4153
    #include "./arch/arm/init_defs.h"
#endif

#ifndef _ASM

#include "../../core/rtl/rtl_defs.h"

#define	DEFAULT_STACK_SIZE		(12 * 4096)

#ifndef	MAX_CPU_NUM
    #pragma	error("Missing macro MAX_CPU_NUM.");
#endif

#ifndef	BOOTLOADER
    #pragma	error("Missing macro BOOTLOADER.");
#endif

typedef struct _krnl_hdr_t {
    address_t	magic;
    void*		code_start;
    size_t		code_size;
    void*		data_start;
    size_t		data_size;
    size_t		header_size;
    address_t	checksum;
} __attribute__((packed)) krnl_hdr_t, *pkrnl_hdr_t;
#endif	//!	_ASM
