#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

MODULE_DESCRIPTION("List current processes");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");

static int my_proc_init(void)
{
    struct task_struct *p; /* Needed for later **/

    printk("Current process: pid = %d; name = %s\n",
    current->pid, current->comm);

    printk("\nProcess list:\n\n");
    /* TODO */

    return 0;
}

static void my_proc_exit(void)
{
    printk("Current process: pid = %d; name = %s\n",
    current->pid, current->comm);
}

module_init(my_proc_init);
module_exit(my_proc_exit);
