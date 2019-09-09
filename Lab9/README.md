# Programarea distribuită în C - MPI
Până acum ați lucrat cu thread-uri în  C și Java.

## Functii MPI
### Init - `MPI_Init(int *argc, char ***argv)`
- Construiește environment-ul în care procesele se vor rula
- De regulă se pasează ca argumente cele din linie din comandă (adică cele din `int main (int argc, char **argv)`)
### Finalize - `MPI_Finalize()`
- Se termină procesele
### Comm_Size
### Comm_Rank
### Send
### Receive
