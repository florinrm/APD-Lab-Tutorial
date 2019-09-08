#include <stdio.h>
#include <mpi.h>

int main (int argc, char **argv) {
    int rank, proc;
    
    MPI_Init(&argc, &argv);
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // rank
    MPI_Comm_size(MPI_COMM_WORLD, &proc);

    // send si receive
    // un proces ii trimite informatia altui proces
    if (rank == 0) {
        int a = 69;
        MPI_Send(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Value %d was sent by the process no. %d\n", a, rank);
    }

    if (rank == 1) {
        int a = 0;
        MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf ("Process no. %d got value %d\n\n", rank, a);
    }

    if (rank == 0) {
        int a = 420;
        for (int i = 1; i < proc; ++i)
            MPI_Send(&a, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        printf("Value %d was sent by process no. %d\n\n", a, rank);
    }

    if (rank != 0) {
        int a = 0;
        MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf ("Process no. %d got value %d\n\n", rank, a);
    }

    MPI_Finalize();
    return 0;
}