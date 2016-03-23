#include <linux/kernel.h>
asmlinkage long sys_hello_world(int i)
{
	printk("Hello world syscall: %d\n",i);
	return 0;
}
