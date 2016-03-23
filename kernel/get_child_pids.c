#include <linux/types.h>
#include <linux/spinlock.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/list.h>
#include <linux/sys.h>
#include <linux/slab.h>

asmlinkage long sys_get_child_pids(pid_t* list, size_t limit, size_t* num_children)
{
	if(!access_ok(pid_t*, list, sizeof(pid_t)))
		return -EFAULT;
	else {
		task_struct* current = find_task_by_vpid(getpid());
	}
	return 0;
}		
