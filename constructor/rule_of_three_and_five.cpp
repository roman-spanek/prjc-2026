//
// Created by roman on 11/05/2026.
//

#include "rule_of_three_and_five.h"

#include <cstring>
#include <iostream>

void my_string::print() {
    std::cout << str << std::endl;
}

my_string::my_string(char *_str) : str(new char[std::strlen(_str) + 1]){
    std::memcpy(str, _str, std::strlen(_str) + 1);
}

my_string::~my_string() {
    delete[] str;
    std::cout << "Destructor called" << std::endl;
}