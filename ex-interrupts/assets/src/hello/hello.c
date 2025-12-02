#include <linux/kernel.h>
#include <linux/module.h>

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");

static int my_init(void)
{
        printk("Hi\n");
        return 0;
}

static void my_exit(void)
{
        printk("Bye\n");
}

module_init(my_init);
module_exit(my_exit);
