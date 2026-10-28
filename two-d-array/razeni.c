#include "razeni.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* qsort předává ukazatele na prvky řazeného pole; prvky jsou ukazatele na int. */
static int porovnejPodleHodnoty(const void *a, const void *b) {
    int x = **(int **) a;
    int y = **(int **) b;
    return (x > y) - (x < y); /* bez přetečení, na rozdíl od x - y */
}

const int **seradObaPole(int *const pole[], const int pocty[], int pocetPoli, int *celkem) {
    if (celkem != NULL) {
        *celkem = 0;
    }
    if (pole == NULL || pocty == NULL || celkem == NULL) {
        return NULL;
    }

    int soucet = 0;
    for (int i = 0; i < pocetPoli; i++) {
        if ((pocty[i] > 0 && pole[i] == NULL) || pocty[i] > SIZE_MAX - soucet) {
            return NULL;
        }
        soucet += pocty[i];
    }
    if (soucet > SIZE_MAX / sizeof(const int *)) {
        return NULL;
    }

    /* Alespoň 1 položka, aby NULL znamenalo vždy chybu (i pro prázdná pole). */
    const int **vysledek = malloc((soucet > 0 ? soucet : 1) * sizeof *vysledek);
    if (vysledek == NULL) {
        return NULL;
    }

    /* Jedno pole ukazatelů odkazující na prvky obou (všech) polí */
    int k = 0;
    for (int i = 0; i < pocetPoli; i++) {
        for (int j = 0; j < pocty[i]; j++) {
            vysledek[k++] = &pole[i][j];
        }
    }

    if (soucet > 1) {
        qsort(vysledek, soucet, sizeof *vysledek, porovnejPodleHodnoty);
        // prozkoumej signaturu metody qsort
        //qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,int (*_PtFuncCompare)(const void *,const void *))
    }

    *celkem = soucet;
    return vysledek;
}

void vypisSerazenePole(const char *popis, const int *const *serazene, int pocet) {
    printf("%s:", popis);
    for (int i = 0; i < pocet; i++) {
        printf(" %d", *serazene[i]);
    }
    printf("\n");
}
