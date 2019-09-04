#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

#define NO_THREADS 10
pthread_barrier_t barrier;

int a = 0, b = 0;

void* printNoBarrier (void* var) {
    int id = *(int *) var;
    printf("Here comes thread no. %d\n", id);

    printf("Thread no. %d likes manele\n", id);
}

void* printWithBarrier (void* var) {
    int id = *(int *) var;
    printf("Here comes thread no. %d\n", id);
    pthread_barrier_wait(&barrier);
    printf("Thread no. %d likes manele\n", id);
}

int main (int argc, int **argv) {

    // array de thread-uri
    pthread_t threads[NO_THREADS], another_threads[NO_THREADS];
    
    // un thread are un id
    int threads_id[NO_THREADS];

    for (int i = 0; i < NO_THREADS; ++i)
        threads_id[i] = i;

    printf("NO BARRIER\n");

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_create(&threads[i], NULL, printNoBarrier, &threads_id[i]);

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_join(threads[i], NULL);

    printf("\nWITH BARRIER\n");

    pthread_barrier_init(&barrier, NULL, NO_THREADS);

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_create(&another_threads[i], NULL, printWithBarrier, &threads_id[i]);

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_join(another_threads[i], NULL);

    pthread_barrier_destroy(&barrier);

    return 0;
}