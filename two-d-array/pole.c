#include "pole.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int *alokujPole(int size) {
    if (size == 0 || size > SIZE_MAX / sizeof(int)) {
        return NULL;
    }
    return malloc(size * sizeof(int));
}

int *presunSude(int **pole, int *pocet, int *pocetSudych) {
    if (pole == NULL || pocet == NULL || pocetSudych == NULL || (*pole == NULL && *pocet > 0)) {
        return NULL;
    }
    int *original = *pole;
    const int n = *pocet;

    /* Kapacita nového pole = původní počet prvků (alespoň 1, aby NULL znamenalo vždy chybu). */
    int *sude = alokujPole(n > 0 ? n : 1);
    if (sude == NULL) {
        return NULL;
    }

    int pocetLichych = 0;
    int pocetS = 0;

    /* Jeden průchod: sudé prvky odcházejí do nového pole, liché se zhušťují na začátek původního.
     * Test "% 2 == 0" funguje správně i pro záporná čísla (-4 % 2 == 0, -3 % 2 == -1). */
    for (int i = 0; i < n; i++) {
        int hodnota = original[i];
        if (hodnota % 2 == 0) {
            sude[pocetS++] = hodnota;
        } else {
            original[pocetLichych++] = hodnota;
        }
    }

    /* Zmenšení paměti původního pole, aby v něm sudé prvky nezůstaly ani jako "zbytky" za koncem. */
    if (pocetLichych == 0) {
        free(original);
        *pole = NULL;
    } else if (pocetLichych < n) {
        int *zmensene = realloc(original, pocetLichych * sizeof(int));
        if (zmensene != NULL) {
            *pole = zmensene; /* při selhání zůstává původní blok platný, jen o něco větší */
        }
    }

    *pocet = pocetLichych;
    *pocetSudych = pocetS;
    return sude;
}

void vypisPole(const char *popis, const int *pole, int pocet) {
    printf("%s:", popis);
    for (int i = 0; i < pocet; i++) {
        printf(" %d", pole[i]);
    }
    printf("\n");
}
