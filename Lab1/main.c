#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

#define NO_THREADS 20

void* thread_function (void* var) {
    int id = *(int *) var;
    printf("Popa si politia din thread-ul %d\n", id);
}

int main (int argc, int **argv) {

    // array de thread-uri
    pthread_t threads[NO_THREADS];
    
    // un thread are un id
    int threads_id[NO_THREADS];

    for (int i = 0; i < NO_THREADS; ++i)
        threads_id[i] = i;

    // cream thread-urile
    for (int i = 0; i < NO_THREADS; ++i)
        pthread_create(&threads[i], NULL, thread_function, &threads_id[i]);

    // dam join la thread-uri / le "distrugem"
    for (int i = 0; i < NO_THREADS; ++i)
        pthread_join(threads[i], NULL);

    return 0;
}