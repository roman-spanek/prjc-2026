#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "heap_memory.h"


int main() {
    int size = 10;
    int *array;
    int *array_start;
    int ret = 0;

    ret = alloc(&array, size);
    if (ret > 0) return ret;

    array_start = array;
    init(array_start, size);
    print(array_start, size);


    free((void *)array_start);

    //STRUCTS
    //priklad 1.
    /*
        LIDE ja, vy;
        POLE a, b;
        ja.vaha = 80;
        ja.vyska = 184;
        vy = ja;
        a.pole[0] = 10;
        b = a;
        b.pole[1] = 20;
        print(ja);
        print(vy);
        printa(a);
        printa(b);
    */
    //priklad 2.
    /*
        POLOZKA *p_a;
        POLOZKA *p_b;
        POLOZKA *p_c;
        p_c = (POLOZKA *)malloc(sizeof(POLOZKA));
        p_c->dalsi = NULL;
        p_c->neco = 30;
        p_a = (POLOZKA *)malloc(sizeof(POLOZKA));
        p_a->neco = 10;
        p_b = (POLOZKA *)malloc(sizeof(POLOZKA));
        p_b->dalsi = p_c;
        p_b->neco = 20;
        p_a->dalsi = p_b;
        print_POLOZKA(p_a);
        free((POLOZKA *)p_c);
        p_c = NULL;
        free((POLOZKA *)p_b);
        p_b = NULL;
        free((POLOZKA *)p_a);
        p_a = NULL;
    */
    //priklad 3.

    ADRESA a1;
    a1.psc = 46008;
    strcpy(a1.ulice,"Narodni");
    LIDE2 ja;
    ja.vaha = 50;
    strcpy(ja.jmeno,"Roman");
    //ja.jmeno = "RomanRomanRomanRomanRomanRoman3233";
    ja.vyska = 180;
    ja.adresa = a1;
    printf("jmeno= %s, vaha =%d, adresa.ulice %s, adresa.pcs %d\n", ja.jmeno,ja.vaha,ja.adresa.ulice,ja.adresa.psc);
    ADRESA a2;
    a2.psc = 66008;
    strcpy(a2.ulice,"Prazska");
    ja.adresa = a2;
    printf("jmeno= %s, vaha =%d, adresa.ulice %s, adresa.pcs %d\n", ja.jmeno,ja.vaha,ja.adresa.ulice,ja.adresa.psc);

    return 0;
}