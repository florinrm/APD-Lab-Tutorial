# Laboratorul 11
## Blocant vs non-blocant
- diferenta dintre functiile blocante si non-blocante este aceea ca cele blocante se blocheaza cand buffer-ul de care ne folosim pentru trimiterea datelor este full
- [lectura suplimentara](https://stackoverflow.com/questions/10017301/mpi-blocking-vs-non-blocking)
## Functii MPI
### `MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)`
- versiune non-blocanta de send (MPI_Send e blocanta)
- `request` este folosit pentru MPI_Wait
### `MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request * request)`
- versiune non-blocanta de recv
### `MPI_Wait(MPI_Request *request, MPI_Status *status);`
- apel de wait, folosit de regula dupa MPI_Irecv, procesul asteapta sa ii fie trimise date noi, dupa ce a primit alte date
### `MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)`
- functie pentru a testa daca s-au trimis / primit datele cu succes
### `MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status)`
- reprezinta o implementare de MPI_Isend-MPI_Irecv, folosind MPI_Wait, unde un proces trimite date altui proces
### `MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)`
- versiune blocanta si sincronizata de send. Aici, un proces trimite informatii altui proces, care trimite o confirmare catre primul proces legata de receptionarea datelor (este nevoie de confirmare pentru a se continua trimiterea datelor).
