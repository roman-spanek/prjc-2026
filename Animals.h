//
// Created by roman on 11/24/2026.
//
#ifndef ZVIRE_H
#define ZVIRE_H

/*
 * Abstraktní třída Zvire.
 * Jméno je dynamicky alokované (char*), proto má třída copy konstruktor
 * (hluboká kopie) a virtuální destruktor.
 */
class Zvire {
protected:
    char* m_jmeno;

public:
    Zvire(const char* jmeno);

    // Copy konstruktor: hluboká kopie jména
    Zvire(const Zvire& other);
    // Virtuální destruktor: delete přes ukazatel na Zvire zavolá i destruktor potomka.
    virtual ~Zvire();

    const char* jmeno() const;

    // Čistě virtuální metody, potomci je musí definovat.
    virtual const char* ozvi_se() const = 0;   // vrací zvuk, který zvíře vydá
    virtual Zvire* klonuj() const = 0;         // vytvoří kopii zvířete (skutečného typu)

    // Vytvoří potomka: naklonuje matku (this) a ke zkopírovanému jménu přidá "_*".
    // Vrácený objekt je alokovaný pomocí new, smazat ho musí volající.
    Zvire* potomek() const;
};


class Pes : public Zvire {
public:
    Pes(const char* jmeno);

    const char* ozvi_se() const override;
    Zvire* klonuj() const override;
};


class Kocka : public Zvire {
public:
    Kocka(const char* jmeno);

    const char* ozvi_se() const override;
    Zvire* klonuj() const override;
};

#endif //PRJC_2026_ANIMALS_H
