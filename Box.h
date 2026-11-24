//
// Created by roman on 11/24/2026.
//

#ifndef PRJC_2026_BOX_H
#define PRJC_2026_BOX_H
#include "Animals.h"
/*
 * Přepravní box. Lze do něj vložit libovolné zvíře (ukazatel na Zvire).
 * Box zvíře vlastní: při vložení ho převezme a v destruktoru ho smaže.
 */
class Box {
private:
    Zvire* m_zvire;
public:
    Box();
    ~Box();
    // Vloží zvíře do boxu (případné původní zvíře se smaže).
    void vloz(Zvire* zvire);
    const Zvire* zvire() const;
};
#endif //PRJC_2026_BOX_H
