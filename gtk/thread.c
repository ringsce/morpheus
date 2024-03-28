#include "thread.h"
#include <stdio.h>
#include <unistd.h>

// Function definition for the thread
void *thread_function(void *arg) {
    int thread_id = *((int *) arg);
    printf("Thread %d is running\n", thread_id);

    // Simulate some work
    sleep(2);

    printf("Thread %d finished\n", thread_id);
    pthread_exit(NULL);
}
