#include <stdio.h>
#include <mpi.h>

/*
    Implementarea algoritmului inel (de tip unda)
*/

int main (int argc, char **argv) {
    int rank, proc, token; // tokenul e transmis de la un proces la altul
    
    // initializam procesele
    MPI_Init(&argc, &argv);
    
    // fiecare proces are un rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // rank
    // stabilim numarul de procese
    MPI_Comm_size(MPI_COMM_WORLD, &proc);

    if (rank != 0) {
        // procesul r primeste tokenul de la veciul r - 1, r > 0
        MPI_Recv(&token, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf ("Process no. %d got token %d from %d\n\n", rank, token, rank - 1);
    } else {
        token = 69; // in procesul initializator
    }

    // se trimite token-ul la urmatorul vecin din inel
    MPI_Send(&token, 1, MPI_INT, (rank + 1) % proc, 0, MPI_COMM_WORLD);
    printf ("Process no. %d sent token %d to %d\n\n", rank, token, (rank + 1) % proc);

    if (rank == 0) {
        // primeste de la ultimul proces din inel (procesul n - 1, n = numarul de procese)
        MPI_Recv(&token, 1, MPI_INT, proc - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf ("Process no. %d got token %d from %d\n\n", rank, token, proc - 1);
    }

    MPI_Finalize();
    return 0;
}