//
// Created by roman on 10/17/2026.
//

#ifndef PRJC_2026_STRUCTS_H
#define PRJC_2026_STRUCTS_H

typedef struct{
    int vaha;
    int vyska;
}LIDE;

typedef struct{
    int pole[10];
}POLE;

/*
//priklad 2. a.
typedef struct polozka{
    int neco;
    polozka dalsi;
};

//priklad 2. b.
typedef struct {
    int neco;
    POLOZKA dalsi;
}POLOZKA;
*/
//priklad 2. c.

typedef struct polozka{
    int neco;
    struct polozka *dalsi;
} POLOZKA;

typedef struct {
    char ulice[30];
    int psc;
}ADRESA;

typedef struct {
    char jmeno[35];
    int vaha;
    int vyska;
    ADRESA adresa;
}LIDE2;


void print_struct(LIDE lide);

void print_POLOZKA(POLOZKA *a);

void printa(POLE pole);
#endif //PRJC_2026_STRUCTS_H
