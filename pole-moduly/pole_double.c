#include "pole_double.h"

#include <stdio.h>
#include <stdlib.h>

double *alokujPoleDouble(int N){
    if (N <= 0) {
        return NULL;
    }
    return malloc(N * sizeof(double));
}

void naplnPoleDoubleNahodne(double *pole, int N, double min, double max)
{
    if (pole == NULL) {
        return;
    }
    for (int i = 0; i < N; i++) {
        double podil = (double)rand() / ((double)RAND_MAX + 1.0);
        pole[i] = min + (max - min) * podil;
    }
}

void vypisPoleDouble(double *pole, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%.3f ", *(pole + i));
    }
    printf("\n");
}
