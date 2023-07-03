/* Driver read function */

static ssize_t my_read(struct file *file, 
        char __user *user_buffer,
        size_t size, loff_t *offset)
{
    struct my_device_data *data =
        (struct my_device_data *) file->private_data;
    size_t to_read;


    /* Copy data->buffer to user_buffer using copy_to_user */
to_read = (size > data->size - *offset) ? (data->size - *offset) : size;
    if (copy_to_user(user_buffer, data->buffer + *offset, to_read) != 0)
        return -EFAULT;
    *offset += to_read;

    return to_read;
}

/* Driver write function */

static ssize_t my_write(struct file *file,
        const char __user *user_buffer,
        size_t size, loff_t *offset)
{
    struct my_device_data *data =
        (struct my_device_data *) file->private_data;


    /* Copy user_buffer to data->buffer, using copy_from_user */
    size = (*offset + size > BUFSIZ) ? (BUFSIZ - *offset) : size;
    if (copy_from_user(data->buffer + *offset, user_buffer, size) != 0)
        return -EFAULT;
    *offset += size;
    data->size = *offset;

    return size;
}

