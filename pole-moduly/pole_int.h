#ifndef POLE_INT_H
#define POLE_INT_H

#include <stddef.h>

/* Pole int, které si nese svoji velikost (v C pole délku samo nezná). */
typedef struct {
    int    *data;
    int  velikost;
} PoleInt;


int vytvorPoleIntZPrvku(double *poleD, int N, int n, PoleInt *vysledek);

/* Uvolní data a pole vynuluje. */
void uvolniPoleInt(PoleInt *pole);

/* Vypíše pole na jeden řádek. */
void vypisPoleInt(PoleInt *pole);

#endif
