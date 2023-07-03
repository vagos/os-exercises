const struct file_operations my_fops = {
    .owner = THIS_MODULE,
    .open = my_open,
    .read = my_read,
    .write = my_write,
    .release = my_release,
};

static int my_init(void)
{
    /* ... */

/* When initialising your device, pass in the my_fops variable. */
    cdev_init(&devs[i].cdev, &my_fops);

    /* ... */

}
