#include <stdio.h>
#include <mpi.h>

#define ROOT 0

const int chunks_per_process = 5; // numarul de elemente per proces

int* create_array (int size) {
    int* arr = (int*) malloc (size * sizeof(int));
    
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }

    return arr;
}

int* increaseEveryElement (int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i]++;
    }

    return arr;
}

int main (int argc, char **argv) {
    int rank, proc, a;

    int* arr;
    
    // initializam procesele
    MPI_Init(&argc, &argv);
    
    // fiecare proces are un rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // rank
    // stabilim numarul de procese
    MPI_Comm_size(MPI_COMM_WORLD, &proc);

    // procesul root seteaza valoarea lui a
    if (rank == ROOT) {
        arr = create_array(chunks_per_process * proc);
    }

    printf("Process no. %d got value %d\n", rank, a);

    MPI_Finalize();
    return 0;
}