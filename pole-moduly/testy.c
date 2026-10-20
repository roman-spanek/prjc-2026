#include "testy.h"

#include <limits.h>
#include <math.h>
#include <stdio.h>

#include "pole_int.h"

/* ------------------------------------------------------------------ */
/*  Tabulka scenarů: vstup -> ocekavany vystup                          */
/* ------------------------------------------------------------------ */

typedef struct {
    double *vstup; /* vstupni pole double (můze byt NULL)         */
    int N; /* velikost vstupniho pole                     */
    int n; /* index prvku, ze ktereho se bere velikost    */
    int ocekavanyStav; /* ocekavany navratovy kód                     */
    int ocekavanaVelikost; /* ocekavana velikost pole int (0 = prazdne)   */
} PripadTestu;

static PripadTestu PRIPADY[] = {
    /* ---- bezne scenare ---- */
    {(double[]){2.7, 5.9, 0.3}, 3, 1, 0, 5},
    {(double[]){4.0, 1.0}, 2, 0, 0, 4},
    {(double[]){1.0, 2.0, 9.99}, 3, 2, 0, 9},
    {(double[]){3.0}, 1, 0, 0, 3},
    {(double[]){7.0}, 1, 0, 0, 7},
    {(double[]){5.99}, 1, 0, 0, 5},
    {(double[]){-5.0, 2.0, NAN, -1.0}, 4, 1, 0, 2},

    /* ---- hranice velikosti ---- */
    {(double[]){1.0}, 1, 0, 0, 1},
    {(double[]){0.99}, 1, 0, 0, 0},
    {(double[]){0.0}, 1, 0, 0, 0},
    {(double[]){-0.0}, 1, 0, 0, 0},

    /* ---- n-ty prvek nelze pouzit jako velikost ---- */
    {(double[]){-3.2}, 1, 0, 10, 0},
    {(double[]){-0.5}, 1, 0, 10, 0},
    {(double[]){NAN}, 1, 0, 10, 0},
    {(double[]){INFINITY}, 1, 0, 10, 0},
    {(double[]){-INFINITY}, 1, 0, 10, 0},
    {(double[]){(double) INT_MAX + 1.0}, 1, 0, 10, 0},
    {(double[]){3e10}, 1, 0, 10, 0},

    /* ---- neplatne argumenty ---- */
    {(double[]){1.0, 2.0, 3.0}, 3, 3, 1, 0},
    {(double[]){1.0, 2.0, 3.0}, 3, 100, 1, 0},
    {(double[]){1.0}, 0, 0, 1, 0},
    {NULL, 3, 0, 1, 0},
};



/* Spusti jeden scenar z tabulky. Vraci 1 = prosel, 0 = selhal . */
static int provedPripad(PripadTestu *p) {
    /* Vysledek predem naplnime "spatnou" hodnotou - funkce ho musi vzdy prepsat. */
    PoleInt v = {NULL, 12345};
    int ok = 1;

    int stav = vytvorPoleIntZPrvku(p->vstup, p->N, p->n, &v);

    if (stav != p->ocekavanyStav) {
        printf("ocekavany stav %d, skutecny %d", p->ocekavanyStav, stav);
        ok = 0;
    } else if (v.velikost != p->ocekavanaVelikost) {
        printf("ocekavana velikost %d, skutecna %d", p->ocekavanaVelikost, v.velikost);
        ok = 0;
    } else if ((v.velikost == 0) != (v.data == NULL)) {
        printf("data musi byt NULL prave tehdy, kdyz je velikost 0");
        ok = 0;
    } else {
        for (int i = 0; i < v.velikost; i++) {
            if (v.data[i] != i) {
                printf( "data[%d] ma byt %d, je %d", i, i, v.data[i]);
                ok = 0;
                break;
            }
        }
    }
    uvolniPoleInt(&v);
    return ok;
}

/* ------------------------------------------------------------------ */

int spustTesty(void) {
    int pocetPripadu = sizeof PRIPADY / sizeof PRIPADY[0]; //tady to jde, protoze PRIPADY je pole struktur, ne pointer na strukturu!!!!!!
    int celkem = 0;
    int selhalo = 0;

    printf("=== Testy funkce vytvorPoleIntZPrvku ===\n");

    for (int i = 0; i < pocetPripadu; i++) {
        int ok = provedPripad(&PRIPADY[i]);
        celkem++;
        selhalo += !ok;
    }

    printf("Vysledek: %d z %d scenaru proslo.\n", celkem - selhalo, celkem);
    return selhalo;
}
