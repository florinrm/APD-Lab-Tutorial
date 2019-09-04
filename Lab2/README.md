# Multithreading în C (pthreads) - operații pe array-uri

Uneori vrem să paralelizăm operații pe array-uri pentru a face speed-up la program. Unui thread îi revine o bucată din array, în care operează acesta.

Fie P numărul de thread-uri și N mărirea array-ului. Unui thread îi revine o bucată din array de dimensiune N / P, în care acestea operează.
