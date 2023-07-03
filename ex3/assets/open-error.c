int fd = open("/dev/my_device", O_RDONLY);
if (fd < 0) {
    /* handle error */
}

// ...

close(fd);
