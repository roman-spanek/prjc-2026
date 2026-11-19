//
// Created by roman on 11/05/2026.
//

#include "rule_of_three_and_five.h"

int main() {
    char str[] = "AHOJ";

    my_string *s = new my_string(str);
    s->print();          // AHOJ

    str[0] = 'a';

    s->print();          // AHOJ (should remain unchanged)

    delete s;
    s = nullptr;
}
