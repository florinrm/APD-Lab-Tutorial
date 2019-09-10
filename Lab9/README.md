# Programarea distribuită în C - MPI
Până acum ați lucrat cu thread-uri în  C și Java.

## Functii MPI
### Init - `MPI_Init(int *argc, char ***argv)`
- Construiește environment-ul în care procesele se vor rula
- De regulă se pasează ca argumente cele din linie din comandă (adică cele din `int main (int argc, char **argv)`)
### Finalize - `MPI_Finalize()`
- Se termină procesele
### Comm_Size - `MPI_Comm_size(MPI_Comm comm, int *size)`
- Întoarce numărul de procese asociate cu un comunicator (de regulă MPI_COMM_WORLD)
- Exemplu: `MPI_Comm_size(MPI_COMM_WORLD, &tasks)`, unde tasks este numărul de procese
### Comm_Rank
### Send
### Receive
### Broadcast
### Scatter
### Gather

## Utile
[Tutoriale MPI](https://mpitutorial.com/tutorials/)
