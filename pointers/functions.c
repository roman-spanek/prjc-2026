//
// Created by roman on 10/08/2026.
//

#include "functions.h"

#include <stdio.h>

void vymen(int *a1, int *b1) {
    int c = *b1;
    *b1 = *a1;
    *a1 = c;
}

void vymen2(void **a1, void **b1) {
    void *temp;
    temp = *b1;
    *b1 = *a1;
    *a1 = temp;
}

void print(char variable, int value) {
    printf("%c = %d \n",variable, value);
}


void printadr(int *p_i) {
    printf("i at %p \n", p_i);
}