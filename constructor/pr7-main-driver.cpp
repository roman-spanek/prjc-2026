//
// Created by roman on 11/05/2026.
//

#include "rule_of_three_and_five.h"

int main() {
    my_string *s = new my_string("AHOJ");
    s->print();
    delete(s);
    s = nullptr;
}
