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

#ifndef	PM_H_INCLUDE
#define	PM_H_INCLUDE

#include "../common/common.h"

#include "mutex/mutex.h"
#include "semaphore/semaphore.h"
#include "spinlock/arch/x86/spinlock.h"

#define		MAX_PROCESS_NUM		32767
#define		MAX_THREAD_NUM		65535

#define		TASK_RUNNING		0x00
#define		TASK_READY			0x01
#define		TASK_SUSPEND		0x02
#define		TASK_SLEEP			0x03
#define		TASK_ZOMBIE			0x04

#define		PROC_ALIVE			0x00
#define		PROC_ZOMBIE			0x01

#define		PRIORITY_LOWEST		INT_LEVEL_LOWEST
#define		PRIORITY_HIGHEST	INT_LEVEL_USR_HIGHEST
#define		PRIORITY_NORMAL		(INT_LEVEL_USR_HIGHEST / 2)

#define		KERNEL_STACK_SIZE	(4096*2)
#define		USER_STACK_SIZE		(2*1024*1024)

//Thread function
//void			thread_func(u32 thread_id,void* p_args);
typedef	void	(*thread_func)(u32, void*);

#ifdef	X86
	#include "arch/x86/schedule.h"
	#include "arch/x86/process.h"
#endif	//X86

//All
void		pm_init();

//Thread
void		pm_schedule();
u32			pm_create_thrd(thread_func entry, bool is_ready, bool is_user, u32 priority, void* p_args);
void		pm_exit_thrd(u32 exit_code);
void		pm_suspend_thrd(u32 thread_id);
void		pm_resume_thrd(u32 thread_id);
void		pm_sleep(u32 ms);
u32			pm_get_crrnt_thrd_id();
void		pm_task_schedule();
void		pm_clock_schedule();
u32			pm_join(u32 thread_id);
bool		pm_get_proc_id(u32 thread_id, u32* p_proc_id);
void		pm_set_errno(u32 errno);
u32			pm_get_errno();

bool		pm_get_thread_context(u32 id, pcontext p_cntxt);
bool		pm_set_thread_context(u32 id, pcontext p_cntxt);

//Process
s32			pm_fork();
void		pm_exec(char* cmd_line);
u32			pm_wait(u32 child_id);
u32			pm_get_crrnt_process();
bool		pm_get_proc_uid(u32 process_id, u32* p_uid);
bool		pm_set_proc_euid(u32 process_id, u32 euid);
bool		pm_get_proc_euid(u32 process_id, u32* p_euid);
bool		pm_add_proc_file_descriptor(u32 process_id, u32 descriptor);
bool		pm_remove_proc_file_descriptor(u32 process_id, u32 descriptor);

//Spin lock
void		pm_init_spn_lock(pspin_lock p_lock);
void		pm_acqr_spn_lock(pspin_lock p_lock);
void		pm_acqr_raw_spn_lock(pspin_lock p_lock);
bool		pm_try_acqr_spn_lock(pspin_lock p_lock);
bool		pm_try_acqr_raw_spn_lock(pspin_lock p_lock);
void		pm_rls_spn_lock(pspin_lock p_lock);
void		pm_rls_raw_spn_lock(pspin_lock p_lock);

//Mutex
void		pm_init_mutex(pmutex p_mutex);
void		pm_acqr_mutex(pmutex p_mutex);
bool		pm_try_acqr_mutex(pmutex p_mutex);
void		pm_rls_mutex(pmutex p_mutex);

//Semaphore
void		pm_init_semaphore(psemaphore p_semaphore);
void		pm_acqr_semaphore(psemaphore p_semaphore);
bool		pm_try_acqr_semaphore(psemaphore p_semaphore);
void		pm_rls_semaphore(psemaphore p_semaphore);

#endif	//!	PM_H_INCLUDE

