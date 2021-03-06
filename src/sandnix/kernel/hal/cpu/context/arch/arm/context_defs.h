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

#include "../../../../../../../common/common.h"

typedef struct _context {
    u32		r0;
    u32		r1;
    u32		r2;
    u32		r3;
    u32		r4;
    u32		r5;
    u32		r6;
    u32		r7;
    u32		r8;
    u32		r9;
    u32		r10;
    u32		r11;
    u32		r12;
    u32		lr_usr;
    u32		sp_usr;
    u32		lr_svc;
    u32		sp_svc;
    u32		cpsr;
    u32		pc;
} context_t, *pcontext_t;
