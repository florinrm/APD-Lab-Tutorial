#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

#define NO_THREADS 20
pthread_mutex_t mutex;

int a = 0, b = 0;

void* incrementNumberNoMutex (void* var) {
    ++a;
}

void* incrementNumberWithMutex (void* var) {
    pthread_mutex_lock(&mutex);
    ++b;
    pthread_mutex_unlock(&mutex);
}

int main (int argc, int **argv) {

    // array de thread-uri
    pthread_t threads[NO_THREADS], another_threads[NO_THREADS];
    
    // un thread are un id
    int threads_id[NO_THREADS];

    for (int i = 0; i < NO_THREADS; ++i)
        threads_id[i] = i;

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_create(&threads[i], NULL, incrementNumberNoMutex, &threads_id[i]);

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_join(threads[i], NULL);

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_create(&another_threads[i], NULL, incrementNumberWithMutex, &threads_id[i]);

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_join(another_threads[i], NULL);

    pthread_mutex_destroy(&mutex);

    printf("No mutex - a: %d\n", a);
    printf("With mutex - b: %d\n", b);

    return 0;
}