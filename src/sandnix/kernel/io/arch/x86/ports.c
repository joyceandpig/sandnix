/*
	  Copyright 2016,暗夜幽灵 <darknightghost.cn@gmail.com>

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

#include "../../io.h"

void io_read_port_bytes(u32 port, u8* buf, u32 num)
{
	__asm__ __volatile__(
	    "cld\n"
	    "rep		insb\n"
	    ::"d"(port), "D"(buf), "c"(num));
	return;
}

void io_write_port_bytes(u32 port, u8* buf, u32 num)
{
	__asm__ __volatile__(
	    "cld\n"
	    "rep		outsb\n"
	    ::"d"(port), "S"(buf), "c"(num));
	return;
}

void io_read_port_words(u32 port, u16* buf, u32 num)
{
	__asm__ __volatile__(
	    "cld\n"
	    "rep		insw\n"
	    ::"d"(port), "D"(buf), "c"(num));
	return;
}
void io_write_port_words(u32 port, u16* buf, u32 num)
{
	__asm__ __volatile__(
	    "cld\n"
	    "rep		outsw\n"
	    ::"d"(port), "S"(buf), "c"(num));
	return;
}

void io_read_port_dwords(u32 port, u32* buf, u32 num)
{
	__asm__ __volatile__(
	    "cld\n"
	    "rep		insl\n"
	    ::"d"(port), "D"(buf), "c"(num));
	return;
}

void io_write_port_dwords(u32 port, u32* buf, u32 num)
{
	__asm__ __volatile__(
	    "cld\n"
	    "rep		outsl\n"
	    ::"d"(port), "S"(buf), "c"(num));
	return;
}

u8 io_read_port_byte(u32 port)
{
	u8 data;
	__asm__ __volatile__(
	    "inb		%1,%%al\n"
	    :"=%%al"(data)
	    :"dx"((u16)port));
	return data;
}

void io_write_port_byte(u8 data, u32 port)
{
	__asm__ __volatile__(
	    "outb		%0,%1\n"
	    ::"al"(data), "dx"((u16)port));
	return;
}

u16 io_read_port_word(u32 port)
{
	u16 data;
	__asm__ __volatile__(
	    "inw		%1,%%ax\n"
	    :"=%%ax"(data)
	    :"dx"((u16)port));
	return data;
}

void io_write_port_word(u16 data, u32 port)
{
	__asm__ __volatile__(
	    "outw		%0,%1\n"
	    ::"ax"(data), "dx"((u16)port));
	return;
}

u32 io_read_port_dword(u32 port)
{
	u32 data;
	__asm__ __volatile__(
	    "inl		%1,%%eax\n"
	    :"=%%eax"(data)
	    :"dx"((u16)port));
	return data;
}

void io_write_port_dword(u32 data, u32 port)
{
	__asm__ __volatile__(
	    "outl		%0,%1\n"
	    ::"eax"(data), "dx"((u16)port));
	return;
}

void io_delay()
{
	__asm__ __volatile__(
	    "nop\n"
	    "nop\n"
	    "nop\n"
	    "nop\n"
	);
	return;
}