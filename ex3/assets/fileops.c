#include <linux/fs.h>

struct file_operations {
    struct module *owner;
    // [...]
    ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);

    ssize_t (*write) (struct file*, const char __user*, size_t, loff_t*);

    // [...]
    int (*open) (struct inode *, struct file *);
    // [...]
    int (*release) (struct inode *, struct file *);
    // [...]
