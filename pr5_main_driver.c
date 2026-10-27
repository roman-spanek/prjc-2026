#include <stdio.h>
#include <stdlib.h>

void fill(int **x4, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < x4[i][0]; j++) {
            x4[i][j] = i + j;
        }
    }
}
void print(int *x4[], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < x4[i][0]; j++) {
            printf("%d ", x4[i][j]);
        }
       printf("\n");
    }

}

void fee(int **x4, int rows) {
    if (x4 == NULL || rows <= 0) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        free(x4[i]);
        x4[i] = NULL;
    }
    free(x4);
    x4 = NULL;
}

int ** allocate_2d(int rows) {
    if (rows <= 0) {
        return NULL;
    }
    int ** x4 = (int **)malloc(sizeof(int *) * rows);

    for (int i = 0; i < 4; i++) {
        x4[i] = (int *)malloc(sizeof(int) * (i + 3));
        x4[i][0] = (i + 3);
    }
    return x4;
}
int main() {

    int **x4;
    int rows = 4;
    x4 = allocate_2d(rows);


    fill(x4, rows);
    print(x4, rows);

    return 0;
}
