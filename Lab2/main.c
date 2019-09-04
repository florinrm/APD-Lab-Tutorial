#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

#define NO_THREADS 20

int size = 69, n_threads = NO_THREADS;
int* arr;

int min (int a, int b) {
    return a <= b ? a : b;
}

void* thread_function (void* var) {
    int id = *(int*) var;

    int start = id * ceil((double) size / (double) n_threads);
	int end = min(((id + 1) * ceil((double) size / (double) n_threads)), size);

    for (int i = start; i < end; ++i) {
        arr[i]++;
    }
}

int main (int argc, int **argv) {

    pthread_t threads[NO_THREADS];
    
    int threads_id[NO_THREADS];

    arr = malloc (size * sizeof(int));

    for (int i = 0; i < NO_THREADS; ++i) {
        threads_id[i] = i;
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_create(&threads[i], NULL, thread_function, &threads_id[i]);

    for (int i = 0; i < NO_THREADS; ++i)
        pthread_join(threads[i], NULL);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}