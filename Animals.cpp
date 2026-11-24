//
// Created by roman on 11/24/2026.
//

#include "Animals.h"

#include <cstring>

Zvire::Zvire(const char* jmeno) {
    m_jmeno = new char[std::strlen(jmeno) + 1];
    std::strcpy(m_jmeno, jmeno);
}

Zvire::Zvire(const Zvire& other) {
    m_jmeno = new char[std::strlen(other.m_jmeno) + 1];
    std::strcpy(m_jmeno, other.m_jmeno);
}

Zvire::~Zvire() {
    delete[] m_jmeno;
}

const char* Zvire::jmeno() const {
    return m_jmeno;
}

Zvire* Zvire::potomek() const {
    Zvire* mlade = klonuj();

    char* noveJmeno = new char[std::strlen(m_jmeno) + std::strlen("_*") + 1];
    std::strcpy(noveJmeno, m_jmeno);
    std::strcat(noveJmeno, "_*");

    delete[] mlade->m_jmeno;     // zahodíme zkopírované jméno
    mlade->m_jmeno = noveJmeno;
    return mlade;
}

Pes::Pes(const char* jmeno) : Zvire(jmeno) {}

const char* Pes::ozvi_se() const {
    return "Haf!";
}

// new Pes(*this) zavolá copy konstruktor třídy Pes (a tím i třídy Zvire)
Zvire* Pes::klonuj() const {
    return new Pes(*this);
}

Kocka::Kocka(const char* jmeno) : Zvire(jmeno) {}

const char* Kocka::ozvi_se() const {
    return "Mnau!";
}

Zvire* Kocka::klonuj() const {
    return new Kocka(*this);
}
