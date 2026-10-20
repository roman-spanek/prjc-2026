#ifndef POLE_DOUBLE_H
#define POLE_DOUBLE_H

/* Alokuje pole N hodnot typu double (neinicializované).
 * Vrací NULL, pokud je N == 0 nebo se alokace nezdařila.
 * Uvolnění je na volajícím (free). */
double *alokujPoleDouble(int N);

/* Naplní pole N hodnot náhodnými čísly z intervalu <min, max).
 * Generátor (srand) inicializuje volající jednou na začátku programu. */
void naplnPoleDoubleNahodne(double *pole, int N, double min, double max);

/* Vypíše pole na jeden řádek. */
void vypisPoleDouble(double *pole, int N);

#endif
