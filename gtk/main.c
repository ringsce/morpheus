#include "thread.h"
#include <stdio.h>

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    // Create thread 1
    if (pthread_create(&thread1, NULL, thread_function, (void *)&id1)) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    // Create thread 2
    if (pthread_create(&thread2, NULL, thread_function, (void *)&id2)) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads finished\n");

    return 0;
}
