# Probleme date în trecut la examene
1) Avem un graf conex oarecare, un nod v și lista lui de vecini. Să se afle nodul maxim (adică nodul cu numărul cel mai mare de vecini din graf), folosind un algoritm distribuit de tip undă.

**Soluție**: aflăm topologia grafului folosind algoritmul sondă-ecou (forma generală), apoi, după ce aflăm topologia grafului, vedem care este nodul maxim
```
typedef enum {sonda, ecou} fel;
typedef tip_leg bool[1:n];
typedef tip_top bool[1:n][1:n];

chan sonda_ecou[1:n] (fel k, int nod, tip_top topologie);
chan ch[1:n] (int data, int nod);

process Find [p = 1 to n] {
  int parent = n + 1; // nodul parinte
  int ecouri = 0; // nr de ecouri
  tip_leg leg = vecini(p);
  
  // top e topologia globala, top_nou e topologia locala unui nod
  tip_top top = calloc(false, n*n), top_nou;
  top[p, 1:n] = leg; // adaugam in graf pe p si vecinii lui
  
  // daca p nu este nod initiator, primeste sonda de la parintele sau
  if (not initiator(p)) {
    receive sonda_ecou[p](sonda, parent, top_nou);
  }
  
  // trimitem sonda tuturor vecinilor, cu topologia globala pe care o construim
  for (q = 1 to n st (leg[q] && q != parent)) {
    send sonda_ecou[q](sonda, p, top);
    ++ecouri;
  }
  
  // acum primim sonda sau ecou de la vecini si construim topologia globala
  while (ecouri > 0) {
    receive sonda_ecou[p](k, q, top);
    if (k == sonda)
      send sonda_ecou[q](sonda, p, null); // trimitem sonda cu topologia nula
    else if (k == ecou) {
      top = top or top_nou;
      --ecouri;
    }
  }
  
  // trimitem topologia construita tuturor nodurilor
  for (q = 1 to n st (leg[q] && q != parent)) {
    send sonda_ecou[q](ecou, p, top);
  }
  // trimitem la nodul parinte, daca se aplica cazul
  if (not initiator(p)) {
    send sonda_ecou[parent](ecou, p, top);
  }
  
  // acum avem topologia, cautam nodul cu gradul maxim (cel mai mare numar de vecini)
  int max_nod = 1, max_vecini = 0;
  // parcurgem graful linie cu linie
  for (q = 1 to n) {
    int vecini_linie = 0;
    for (j = 1 to n) {
      if (top[q][j])
        ++vecini_linie;
    }
    if (vecini_linie >= max_vecini) {
      max_vecini = vecini_linie;
      max_nod = q;
    }
  }
  
  // transmitem tuturor nodurilor cine e nodul maxim
  for (q = 1 to n st (leg[q])) {
    send ch[q](max_nod, p);
  }
}
```
2) Avem două procese, fiecare cu câte o listă. Să se interschimbe astfel încât orice element din prima listă e mai mic decât orice element din a doua listă.
