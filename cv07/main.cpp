#include <iostream>
#include "Vektor.h"

// Pomocná funkce pro výpis vektoru ve tvaru (1, 2, 3).
// Bere nekonstantní referenci, protože operator[] existuje jen v nekonstantní verzi.
// Objekt se předává referencí, takže nevzniká kopie.
void vypis(Vektor& v) {
    std::cout << "(";
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << v[i];
    }
    std::cout << ")\n";
}

int main() {
    Vektor a(3, 1.0);
    Vektor b(3);
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;

    std::cout << "a = ";
    vypis(a);
    std::cout << "b = ";
    vypis(b);

    a += b;
    std::cout << "a += b -> ";
    vypis(a);

    a *= 2;
    std::cout << "a *= 2 -> ";
    vypis(a);

    // operátory vracejí referenci, proto je lze řetězit
    (b += b) *= 3;
    std::cout << "(b += b) *= 3 -> ";
    vypis(b);

    Vektor c(3);
    c[0] = 4;
    c[1] = 6;
    c[2] = 8;
    Vektor d(2, 4.0);

    std::cout << "a == b: " << (a == b ? "ano" : "ne") << "\n";
    std::cout << "a == c: " << (a == c ? "ano" : "ne") << "\n";
    std::cout << "a == d: " << (a == d ? "ano" : "ne") << "\n";

    {
        Vektor tmp(5, 7.5);
        std::cout << "tmp = ";
        vypis(tmp);
    }   // tady se zavolá destruktor objektu tmp

    std::cout << "konec programu\n";
    return 0;
}
