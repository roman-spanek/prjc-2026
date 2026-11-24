//
// Created by roman on 11/24/2026.
//
#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>

#include "Animals.h"
#include "Box.h"

int main() {
    // Původní zvířata (matky)
    Pes punta("Punta"), bety("Bety"), lenka("Lenka");
    Kocka micka("Micka"), liza("Liza"), mourka("Mourka");

    const int N = 6;
    Box boxy[N];
    //void Box::vloz(Zvire* zvire)
    boxy[0].vloz(&punta);
    boxy[1].vloz(micka.potomek());
    boxy[2].vloz(liza.potomek());
    boxy[3].vloz(bety.potomek());
    boxy[4].vloz(lenka.potomek());
    boxy[5].vloz(mourka.potomek());


    // Určení zvířete v každém boxu podle toho, co vydá ozvi_se()
    for (int i = 0; i < N; i++) {
        std::cout << "Box " << i + 1 << ": " << boxy[i].zvire()->ozvi_se()
        << " -> " << boxy[i].zvire()->jmeno() << "\n";
    }

/*
    std::deque<Box> boxy;

    // Naplnění boxů: zvířata vznikají klonováním matky, jméno = jméno matky + "_*"
    for (const Zvire* matka : matky) {
        boxy.emplace_back();                    // přidá nový prázdný box na konec
        boxy.back().vloz(matka->potomek());     // vloží do něj potomka matky
    }

    // Další box lze přidat kdykoli později
    boxy.emplace_back();
    boxy.back().vloz(boxy[0].zvire()->potomek()->klonuj());

    // Určení zvířete v každém boxu podle toho, co vydá ozvi_se()
    for (std::size_t i = 0; i < boxy.size(); i++) {
        std::cout << "Box " << i + 1 << ": " << boxy[i].zvire()->ozvi_se() << " -> " << boxy[i].zvire()->jmeno() << "\n";
    }
*/
    return 0;
}