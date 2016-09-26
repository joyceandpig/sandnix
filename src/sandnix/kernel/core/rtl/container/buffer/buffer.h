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

#include "../../../../../../common/common.h"

typedef	struct _buffer {
    u8*		p_buffer;
    size_t	size;
    u8*		p_begin;
    u8*		p_end;
    bool	is_full;
    bool	overwrite;
} buffer_t, *pbuffer_t;

//Initialize
void core_rtl_buffer_init(
    pbuffer_t p_buffer,
    size_t size,
    void* buf,
    bool overwrite);

//Read
size_t core_rtl_buffer_read(
    pbuffer_t p_buffer,
    void* p_buf,
    size_t len_to_read,
    bool block);

//Write
size_t core_rtl_buffer_write(
    pbuffer_t p_buffer,
    void* p_data,
    size_t len_to_write,
    bool block,
    bool overwrite);