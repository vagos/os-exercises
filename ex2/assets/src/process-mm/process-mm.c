#include "asm/processor.h"
#include "linux/list.h"
#include "linux/nodemask.h"
#include "linux/printk.h"
#include "linux/sched.h"
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_DESCRIPTION("Info about a process and it's children.");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");

static struct timer_list check_timer; 

#define DELAY HZ/10
static int PID; 

/* module parameters for setting the PID */
module_param(PID, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
MODULE_PARM_DESC(PID, "The process PID"); 

static void print_process_info(struct timer_list *unused) 
{ 
    struct task_struct* task;
    struct task_struct* child;

    /* Synchronization mechanism needed before searching for the process */
    rcu_read_lock();

    /* Search through the global namespace for the process with the given PID */
    task = pid_task(find_pid_ns(PID, &init_pid_ns), PIDTYPE_PID);

    if (task)
    {
        /* TODO: print the number of processes accesing the process' memory. */
        printk("pid: %d, name: %s\n", task->pid, task->comm);
        printk("Users: %d", atomic_read(&task->mm->mm_users));
    }

    rcu_read_unlock(); /* Task pointer is now invalid! */

    /* Restart the timer. */
    check_timer.expires = jiffies + DELAY;
    add_timer(&check_timer); 
} 


static int my_init(void)
{

    /* 
       Timers are a kernel mechanism to execute a function at a given time. 
       They take as arguments a pointer to a timer_list struct, a callback function and some flags. 
       We want to have the print_process_info function run every DELAY ticks.
       That's why we need to restart the timer inside the function.
       Remember to delete the timer on the module exit function. 
    */

    timer_setup(&check_timer, print_process_info, 0); 
    
    /* 
       jiffies in the variable that holds the number of ticks since the machine booted.
       We want our callback function to execute after DELAY ticks. 
    */
    check_timer.expires = jiffies + DELAY; 
    
    /* Insert the timer to the global list of active timers. */
    add_timer(&check_timer); 

    return 0;
}

static void my_exit(void)
{
    /* Finally, remove the timer. */
    del_timer(&check_timer); 
}

module_init(my_init);
module_exit(my_exit);
