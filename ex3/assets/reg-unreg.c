static int my_init(void)
{
    int err;
    // register the device
    err = register_chrdev_region(MKDEV(MY_MAJOR, MY_MINOR), 
            NUM_MINORS, MODULE_NAME);
    
    if (err != 0) {
        pr_info("Registered!");
        return err;
    }

    // ...

    return 0;
}

static void my_exit(void)
{
    // .. 

    // unregister the device
    unregister_chrdev_region(MKDEV(MY_MAJOR, MY_MINOR), 
            NUM_MINORS);
}

