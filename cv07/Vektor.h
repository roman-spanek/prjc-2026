//
// Created by roman on 11/10/2026.
//

#ifndef PRJC_2026_VEKTOR_H
#define PRJC_2026_VEKTOR_H
#include <iostream>

class Vektor {
private:
    double* m_data;       // dynamicky alokované pole prvků
    std::size_t m_size;   // počet prvků (dimenze vektoru)

public:
    // Konstruktor a destruktor
    Vektor(std::size_t size, double initialValue = 0.0);
    ~Vektor();

    // Základní metody
    std::size_t size() const;
    double& at(std::size_t i);                 // přístup k prvku
    void add(const Vektor& other);             // přičtení vektoru po složkách
    void scale(double k);                      // vynásobení všech složek skalárem
    bool equals(const Vektor& other) const;    // shoda velikosti i všech prvků

    // Přetížené operátory (jen volají metody výše)
    double& operator[](std::size_t i);
    Vektor& operator+=(const Vektor& other);
    Vektor& operator*=(double k);
    bool operator==(const Vektor& other) const;
};

#endif //PRJC_2026_VEKTOR_H
