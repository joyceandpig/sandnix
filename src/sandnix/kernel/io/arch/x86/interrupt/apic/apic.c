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

#include "../../../../../../../common/common.h"
#include "../../../../../debug/debug.h"
#include "../../../../port.h"
#include "apic.h"
#include "../interrupt.h"

#define	IA32_APIC_BASE		0x001B
#define	LVT_LINT0			0x0350

u32		apic_base_addr;
u32		io_apic_base_addr;

void apic_init()
{
	u32* p_io_apic_index;
	u32* p_io_apic_data;
	u32* p_io_apic_eoi;
	u32 apic_id;
	u32 index;

	dbg_kprint("Initializing APIC...\n");

	dbg_kprint("APIC base address : %P\n", apic_base_addr);
	dbg_kprint("I/O APIC base address : %P\n", io_apic_base_addr);

	//Disable 8259A
	*(u32*)(apic_base_addr + LVT_LINT0) |= 0x10000;
	io_write_port_byte(0xFF, 0x21);

	dbg_kprint("8259A disabled.\n");

	//Enable local APIC
	__asm__ __volatile__(
	    "rdmsr\n"
	    "btsl	$11,%%eax\n"
	    "wrmsr\n"
	    ::"c"(IA32_APIC_BASE)
	    :"ax", "dx");

	//Get current APIC ID
	apic_id = *(u32*)(apic_base_addr + 0x20);
	dbg_kprint("BSP CPU APIC ID : %P.\n", apic_id);

	//I/O APIC enabled in init/arch/x86/init.S
	p_io_apic_index = (u32*)(io_apic_base_addr);
	p_io_apic_data = (u32*)(io_apic_base_addr + 0x10);
	p_io_apic_eoi = (u32*)(io_apic_base_addr + 0x40);

	for(index = 0; index < 23; index++) {
		*p_io_apic_index = IRQ0_INDEX + index * 2;
		*p_io_apic_data = IRQ0 + index;
		*p_io_apic_index = IRQ0_INDEX + index * 2 + 1;
		*p_io_apic_data = apic_id;
		dbg_kprint("IRQ%u ==> INT 0x%.2X.\n", index, IRQ0 + index);
	}

	UNREFERRED_PARAMETER(p_io_apic_eoi);
}
