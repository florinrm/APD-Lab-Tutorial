# Programarea distribuită în C - MPI
Până acum ați lucrat cu thread-uri în  C și Java.
## Tipuri de date in MPI
| Tipul de date in MPI | Tipul de date in C |
| -------------------- |:------------------:|
| MPI_SHORT            | short              |
| MPI_INT              | int                |
| MPI_LONG             | long               |
## Functii MPI
### Init - `MPI_Init(int *argc, char ***argv)`
- Construiește environment-ul în care procesele se vor rula
- De regulă se pasează ca argumente cele din linie din comandă (adică cele din `int main (int argc, char **argv)`)
### Finalize - `MPI_Finalize()`
- Se termină procesele.
### Comm_Size - `MPI_Comm_size(MPI_Comm comm, int *size)`
- Întoarce numărul de procese asociate cu un comunicator (de regulă MPI_COMM_WORLD)
- Exemplu: `MPI_Comm_size(MPI_COMM_WORLD, &tasks)`, unde tasks este numărul de procese
### Comm_Rank - `MPI_Comm_rank(MPI_Comm comm, int *rank)`
- Determină rangul / id-ul unui proces
- Exemplu: `MPI_Comm_rank(MPI_COMM_WORLD, &rank)`, unde rank este rangul / id-ul procesului
### Send - `MPI_Send(void* data, int count, MPI_Datatype datatype, int destination, int tag, MPI_Comm communicator)`
- Un proces-sursă trimite date unui proces-destinatie.

- data = datele trimise
- count = numarul de date trimise
- datatype = tipul datelor trimise
- destination = id-ul procesului destinatie
- tag = tag-ul mesajului trimis (adica al datelor trimise)
- communicator = comunicatorul (de regulă MPI_COMM_WORLD)
### Receive - `MPI_Recv(void* data, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm communicator, MPI_Status* status)`
- Un proces-destinatie primeste date de la un proces-sursa.

- data = datele primite
- count = numarul de date primite
- datatype = tipul datelor primite
- destination = id-ul procesului sursa
- tag = tag-ul mesajului primit (adica al datelor primite)
- communicator = comunicatorul (de regulă MPI_COMM_WORLD)
- status = starea (de regulă se pune MPI_STATUS_IGNORE - se ignoră status-ul)
### Broadcast - `MPI_Bcast(void* data, int count, MPI_Datatype datatype, int root, MPI_Comm communicator)`
- Un proces trimite aceleasi date tuturor proceselor din topologie (inclusiv lui insusi).

- data = datele trimise
- count = numarul de date trimise
- datatype = tipul datelor trimise
- root = id-ul procesului sursa
- communicator = comunicatorul (de regulă MPI_COMM_WORLD)
### Scatter
### Gather

## Utile
[Tutoriale MPI](https://mpitutorial.com/tutorials/)
