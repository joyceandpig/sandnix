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

#include "../../core/rtl/rtl.h"

#include "../early_print/early_print.h"
#include "./context/context.h"
#include "./multiprocessor/multiprocessor.h"

void hal_cpu_init()
{
    hal_early_print_printf("Initializing cpu module...\n");
    cpuinfo_init();
    cpu_ipi_init();
    return;
}
