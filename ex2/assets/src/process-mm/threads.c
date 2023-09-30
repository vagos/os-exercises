#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define THREADS 4

void* 
thread_func(void * __args)
{
    sleep(1);
    return NULL;
}

int main()
{
    printf("PID: %d\n", getpid());

    // sleep(5);

    pthread_t my_threads[THREADS];

    for (int i = 0; i < THREADS; i++)
        pthread_create(&my_threads[i], 
                NULL, thread_func, NULL);

    for (int i = 0; i < THREADS; i++)
        pthread_join(my_threads[i], NULL);
}
