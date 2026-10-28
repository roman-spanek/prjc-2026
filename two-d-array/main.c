#include <stdio.h>
#include <stdlib.h>

#include "pole.h"
#include "razeni.h"

#define SIZE 12

int main(void) {
    /* Vstupni data (záporná čisla, nula i opakovane hodnoty) */
    const int vstup[] = {7, 12, -3, 8, 0, 15, 4, -6, 9, 12, 21, -10};
    /* 1. alokace pole a jeho naplněni */
    int *pole = alokujPole(SIZE);
    if (pole == NULL) {
        printf("Chyba: nepodarilo se alokovat pole.\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < SIZE; i++) {
        pole[i] = vstup[i];
    }
    int pocet = SIZE;
    vypisPole("Puvodni pole", pole, pocet);

    /* 2. presun sudych prvku do noveho pole */
    int pocetSudych = 0;
    int *sude = presunSude(&pole, &pocet, &pocetSudych);
    if (sude == NULL) {
        printf("Chyba: presun sudych prvku se nezdaril.\n");
        free(pole);
        return EXIT_FAILURE;
    }
    printf("\nPo presunu sudych prvku:\n");
    vypisPole("  Puvodni pole (zbyly liche)", pole, pocet);
    vypisPole("  Nove pole (sude)", sude, pocetSudych);

    /* 3. serazeni obou poli najednou - vstupem je jedno pole odkazujici na obě pole */
    int *obePole[2] = {sude, pole};
    int pocty[2] = {pocetSudych, pocet};
    int celkem = 0;

    const int **serazene = seradObaPole(obePole, pocty, 2, &celkem);
    if (serazene == NULL) {
        fprintf(stderr, "Chyba: serazeni se nezdarilo.\n");
        free(sude);
        free(pole);
        return EXIT_FAILURE;
    }

    /* 4. vypis serazeneho pole */
    printf("\n");
    vypisSerazenePole("Serazene prvky obou poli", serazene, celkem);

    /* Puvodni pole zustala beze změny poradi */
    printf("\nPo serazeni (poradi v polich se nezmenilo):\n");
    vypisPole("  Puvodni pole (liche)", pole, pocet);
    vypisPole("  Nove pole (sude)", sude, pocetSudych);

    free(serazene);
    free(sude);
    free(pole);
    return EXIT_SUCCESS;
}
