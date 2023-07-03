#include <asm/uaccess.h>

put_user(type val, type *address);
get_user(type val, type *address);
unsigned long copy_to_user(void __user *to, const void *from,
        unsigned long n);
unsigned long copy_from_user(void *to, const void __user *from,
        unsigned long n);
