#include "pole_int.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int vytvorPoleIntZPrvku(double *poleD, int N, int n, PoleInt *vysledek)
{
    if (vysledek == NULL) {
        return 1;
    }
    vysledek->data = NULL;
    vysledek->velikost = 0;

    if (poleD == NULL || n >= N) {
        return 1;
    }

    double hodnota = poleD[n];
    /* Zápis s negací zachytí i NaN. Horní mez chrání před přetečením při přetypování. */
    if (!(hodnota >= 0.0 && hodnota < (double)INT_MAX)) {
        return 10;
    }

    int velikost = (int)hodnota;   /* přetypování na int zahodí desetinnou část */

    if (velikost > 0) {
        vysledek->data = malloc(velikost * sizeof(int));
        if (vysledek->data == NULL) {
            return 20;
        }
        for (int i = 0; i < velikost; i++) {
            vysledek->data[i] = i;
        }
    }
    vysledek->velikost = velikost;
    return 0;
}

void uvolniPoleInt(PoleInt *pole) {
    if (pole == NULL) {
        return;
    }
    free(pole->data);
    pole->data = NULL;
    pole->velikost = 0;
}

void vypisPoleInt(PoleInt *pole) {
    for (int i = 0; i < pole->velikost; i++) {
        printf("%d ", pole->data[i]);
    }
    printf("\n");
}
