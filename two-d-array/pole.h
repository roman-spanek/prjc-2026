#ifndef POLE_H
#define POLE_H

#include <stddef.h>

/* 1. Alokuje jednorozměrné pole int o velikosti size (neinicializované).
 *    Vrací NULL, pokud je size == 0 nebo se alokace nezdařila.
 *    Uvolnění je na volajícím (free). */
int *alokujPole(int size);

/* 2. Najde sudé prvky v poli a PŘESUNE je do nově alokovaného pole, které vrátí.
 *
 *    pole        - ukazatel na původní pole (*pole); po přesunu v něm zůstanou jen liché prvky
 *                  v původním pořadí a jeho paměť se zmenší (realloc), takže v něm sudé prvky
 *                  fyzicky nezůstanou. Pokud žádné liché prvky nezbudou, pole se uvolní a *pole = NULL.
 *    pocet       - počet prvků původního pole; po přesunu počet zbylých (lichých) prvků
 *    pocetSudych - výstup: počet přesunutých sudých prvků (v novém poli v původním pořadí)
 *
 *    Nové pole má kapacitu rovnou původnímu počtu prvků (nemusíme předem zjišťovat počet sudých).
 *    Vrací NULL jen při chybě (neplatné parametry, nedostatek paměti); původní pole zůstane beze změny. */
int *presunSude(int **pole, int *pocet, int *pocetSudych);

/* Pomocný výpis pole na jeden řádek ve tvaru "popis: a b c". */
void vypisPole(const char *popis, const int *pole, int pocet);

#endif
