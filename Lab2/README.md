# Multithreading în C (pthreads) - operații pe array-uri

Uneori vrem să paralelizăm operații pe array-uri pentru a face speed-up la program. Unui thread îi revine o bucată din array, în care operează acesta.

Fie P numărul de thread-uri și N mărirea array-ului. Unui thread îi revine o bucată din array de dimensiune N / P, în care acestea operează.

Thread-ul cu numărul i operează în array între indecșii start și end, unde:
- start = `i * ceil ((double) N / (double) P)`
- end = `min(N, ((i + 1) * ceil ((double) N / (double) P)))` - aici facem minim pentru a evita erori de tip segmentation fault, căci putem depăși array-ul dacă am lăsa doar `(i + 1) * ceil ((double) N / (double) P)`
