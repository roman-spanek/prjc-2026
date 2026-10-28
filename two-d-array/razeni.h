#ifndef RAZENI_H
#define RAZENI_H

#include <stddef.h>

/* 3. Seřadí prvky více polí NAJEDNOU, aniž by v kterémkoli z nich změnila pořadí prvků.
 *
 *    Vstupem je jedno pole ukazatelů 'pole', které odkazuje na jednotlivá pole (zde na pole sudých
 *    a pole lichých prvků); pocty[i] je počet prvků pole pole[i], pocetPoli počet polí.
 *
 *    Řadí se nepřímo: vytvoří se NOVÉ pole ukazatelů na prvky všech polí a seřadí se tyto ukazatele
 *    vzestupně podle hodnot, na které ukazují. Původní pole zůstávají nedotčená.
 *
 *    Vrací nově alokované pole ukazatelů (uvolnit pomocí free) a v *celkem celkový počet prvků.
 *    Vrací NULL jen při chybě (neplatné parametry, nedostatek paměti).
 *    Ukazatele jsou platné, dokud existují původní pole. */
const int **seradObaPole(int *const pole[], const int pocty[], int pocetPoli, int *celkem);

/* Funkce pro výpis seřazeného pole (pole ukazatelů) na konzoli ve tvaru "popis: a b c". */
void vypisSerazenePole(const char *popis, const int *const *serazene, int pocet);

#endif
