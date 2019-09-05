# Introducere în multithreading (C - pthreads)
// spune la lab de exemplul cu aplicarea unui filtru pe imagine (matricea de imagine)

## Creare de thread-uri
By default, programele se execută secvențial (un singur fir de execuție / thread). Noi folosim thread-uri pentru a eficientiza programele din punctul de vedere al vitezei.

În principiu, când creăm thread-uri, acestea se ”despică” din thread-ul principal și fiecare thread are o funcție pe care o execută.
```c
// funcția executată de thread, iar var este parametrul trimis la thread

void* thread_function (void* var) {
    int id = *(int *) var;
    printf("Popa si politia din thread-ul %d\n", id);
}

pthread_t threads[NO_THREADS];
    
// un thread are o informație (adică are niște date, pe care le pasează funcției pe care o execută)
int threads_id[NO_THREADS];

for (int i = 0; i < NO_THREADS; ++i)
    threads_id[i] = i;

// creăm thread-urile, threads_id[i] fiind parametrul trimis la funcția thread_function executată de thread-ul i
for (int i = 0; i < NO_THREADS; ++i)
    pthread_create(&threads[i], NULL, thread_function, &threads_id[i]);

```
Când am și-au terminat thread-urile treaba, ele se ”unifică” prin join, ele realipindu-se la thread-ul principal.
```c
for (int i = 0; i < NO_THREADS; ++i)
    pthread_join(another_threads[i], NULL);
```

## Mutex
Thread-urile pot să partajeze date (variabile) între ele, pe care să aplice operații. Această chestie ne ridică uneori probleme de sincronizare între thread-uri, deoarece putem să nu avem mereu rezultatul dorit.

Pentru sincronizarea thread-urilor care operează pe date partajate folosim mutex, care permite unui singur thread la un moment dat să opereze în zona respectivă de cod cu date partajate (zona critică).

Pentru exemplificare vedeți fișierul mutex.c, compilați-l cu make și rulați de mai multe ori ./mutex

```c
int b = 0; // variabila partajata de thread-uri

// thread-ul intră în zona critică
pthread_mutex_lock(&mutex);
// zona critică
++b;
// thread-ul iese din zona critică
pthread_mutex_unlock(&mutex);
```
## Barieră
Tot pentru sincronizarea thread-urilor putem folosi bariera.

// insert imagine cu bariera

```c
void* printWithBarrier (void* var) {
    int id = *(int *) var;
    printf("Here comes thread no. %d\n", id);
    // toate thread-urile au ajuns până aici
    pthread_barrier_wait(&barrier);
    printf("Thread no. %d likes manele\n", id);
}
```
## Rulare demo-uri
Rulați de mai multe ori în terminal cele 3 demo-uri (main, mutex, barrier) pentru laborator, pentru a observa comportamentul thread-urilor.

## Lectură suplimentară
[Mai multe chespre multithreading in C - SO](https://ocw.cs.pub.ro/courses/so/laboratoare/laborator-08)

[Multithreading in Python - ASC](http://cs.curs.pub.ro/wiki/asc/asc:lab2:index)
