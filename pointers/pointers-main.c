#include <stdio.h>

#include "functions.h"


int main1() {
    int a = 10;
    int b = 20;
    int *a1;
    int *b1;
    a1 = &a;
    b1 = &b;
    print('a', *a1);
    print('b', b);

    vymen(a1, b1);

    print('a',a);
    print('b', b);


    void *av;
    av = &a;


    printf("%d \n", (*(double *)av));

    return 0;
}

