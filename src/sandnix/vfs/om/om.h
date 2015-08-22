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

#ifndef	OM_H_INCLUDE
#define	OM_H_INCLUDE

#include "../vfs.h"
#include "../../pm/pm.h"
#include "../../rtl/rtl.h"
#include "sys/sys.h"

typedef	struct	_kobject	kobject_t, *pkobject_t;

typedef	void	(*obj_destroyer)(pkobject_t);

struct	_kobject {
	char*				name;
	u32					class;
	size_t				size;
	obj_destroyer		destroy_callback;
	u32					ref_count;
	mutex_t				ref_count_lock;
};

#define	OBJ_MAJOR_CLASS(p_object)	(((p_object)->class) & 0xFFFF0000)
#define	OBJ_MINOR_CLASS(p_object)	(((p_object)->class) & 0x0000FFFF)

//Major class
#define	OBJ_MJ_DRIVER				0x00010000
#define	OBJ_MJ_FILE					0x00020000

//Minor class
//Drivers
#define	OBJ_MN_FS					0x00000001

//Files
#define	OBJ_MN_NORMAL				0x00000001
#define	OBJ_MN_BUS					0x00000002
#define	OBJ_MN_DMA					0x00000003
#define	OBJ_MN_CHAR					0x00000004
#define	OBJ_MN_BLOCK				0x00000005
#define	OBJ_MN_VIDEO				0x00000006

typedef	struct	_driver_obj			driver_obj_t, *pdriver_obj_t;
typedef	struct	_file_obj			file_obj_t, *pfile_obj_t;
typedef	struct	_device_obj			device_obj_t, *pdevice_obj_t;

struct	_driver_obj {
	kobject_t		obj;
	list_t			file_list;
	mutex_t			file_list_lock;
};

struct	_file_obj {
	kobject_t		obj;
	pdriver_obj_t	p_driver;
	pdevice_obj_t	p_parent_dev;
	list_t			child_list;
	mutex_t			child_list_lock;
	list_t			refered_proc_list;
	mutex_t			refered_proc_list_lock;
};

struct	_device_obj {
	file_obj_t		file_obj;
};

void		om_init();

#endif	//!	OM_H_INCLUDE
