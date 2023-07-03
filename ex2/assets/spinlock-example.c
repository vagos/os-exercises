#include <linux/spinlock.h>

DEFINE_SPINLOCK(lock1); 
// (same as) spin_lock_init(&lock1)

spin_lock(&lock1);
/* critical region */
spin_unlock(&lock1);
