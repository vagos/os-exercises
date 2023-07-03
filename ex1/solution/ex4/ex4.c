/* 
    Some info on: 

    Kernel timers: https://www.oreilly.com/library/view/linux-device-drivers/0596000081/ch06s05.html
    RCU lock: https://www.kernel.org/doc/Documentation/RCU/whatisRCU.txt
    Linux Kernel linked lists: https://www.oreilly.com/library/view/linux-device-drivers/0596000081/ch10s05.html
*/

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

#define DELAY HZ
#define PID 1234

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
        printk("pid: %d, name: %s\n", task->pid, task->comm);

        /* TODO: iterate over the process' children and print their PID */
        list_for_each_entry(child, &task->children, sibling) {
            printk("* child pid: %d\n", child->pid);
        }
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
