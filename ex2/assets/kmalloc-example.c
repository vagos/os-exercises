#include <linux/slab.h>

// ... 

// allocate 100 bytes of continuous memory
char* my_memory = kmalloc(100 * sizeof(char), 
        GFP_KERNEL);

// ...
