#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <asm/atomic.h>
#include <linux/spinlock.h>
#include <asm/uaccess.h>

int count = 0;
spinlock_t my_lock;
asmlinkage long sys_get_unique_id(int *uuid)
{
	if (!access_ok(int*, uuid, sizeof(int)))
		return -1000;
	spin_lock(&my_lock);
	count = count + 1;	
	put_user(count, uuid);
	spin_unlock(&my_lock);
	return 0;
}
