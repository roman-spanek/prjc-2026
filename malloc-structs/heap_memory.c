//
// Created by roman on 10/17/2026.
//

#include "heap_memory.h"

#include <stdio.h>
#include <stdlib.h>

void init(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        *(array + i) = i;
    }
    size = size + 100;
}
void print(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("pole[%d] = %d\n", i, *(array+i));
    }
}

int alloc(int **array, int size) {
    *array = (int *)malloc(size * sizeof(int));
    if (*array == NULL) return 10;
    return 0;
}