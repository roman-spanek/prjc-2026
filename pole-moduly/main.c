#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pole_double.h"
#include "pole_int.h"
#include "testy.h"

int main(void)
{
    int N = 10;   /* velikost pole double */
    int n = 3;    /* index prvku, podle kterého vytvoříme pole int */

    srand((unsigned)time(NULL));

    /* 1. alokace pole double */
    double *poleD = alokujPoleDouble(N);
    if (poleD == NULL) {
        fprintf(stderr, "Chyba: nepodařilo se alokovat pole double.\n");
        return EXIT_FAILURE;
    }

    /* 2. naplnění náhodnými hodnotami z <1, 10) */
    naplnPoleDoubleNahodne(poleD, N, 1.0, 10.0);
    printf("Pole double: ");
    vypisPoleDouble(poleD, N);

    /* 3. vytvoření pole int podle n-tého prvku */
    PoleInt poleI;
    int stav = vytvorPoleIntZPrvku(poleD, N, n, &poleI);
    if (stav != 0) {
        fprintf(stderr, "Chyba: pole int se nepodařilo vytvořit (kód %d).\n", (int)stav);
        free(poleD);
        return EXIT_FAILURE;
    }
    printf("poleD[%zu] = %.3f -> velikost pole int = %zu\n", n, poleD[n], poleI.velikost);
    printf("Pole int:    ");
    vypisPoleInt(&poleI);

    uvolniPoleInt(&poleI);
    free(poleD);


    int selhalo = spustTesty();

    return selhalo == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
