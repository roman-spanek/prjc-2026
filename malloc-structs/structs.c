//
// Created by roman on 10/17/2026.
//

#include "structs.h"
#include <stdio.h>


void print_struct(LIDE lide){
    printf("Vaha: %d, vyska= %d \n",lide.vaha, lide.vyska);
}

void print_POLOZKA(POLOZKA *a){
    if (a->dalsi != NULL) {
        //printf("tady\t");
        print_POLOZKA(a->dalsi);
        printf("%d, adresa= %p \n",(*a).neco, a);
    }else
        printf("%d, adresa= %p \n",a->neco, a);
}

void printa(POLE pole){
    register int i;
    for (i = 0; i < sizeof(pole.pole)/sizeof(pole.pole[0]); i++)
        printf("[%d]= %d\n",i, pole.pole[i]);
}
