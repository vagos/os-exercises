obj-m += process-mm.o # Change this for different module names.
 
PWD := $(CURDIR) 
 
all: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules 
 
clean: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

thread: threads.c
	gcc -o thread threads.c -lpthread
