//
// Created by roman on 11/02/2026.
//
#include "Pumpkin.h"
#include <iostream>

int Pumpkin::total_number = 0;
int Pumpkin::total_weight = 0;

Pumpkin::Pumpkin(int _weight) : weight(_weight) {
    total_weight += _weight;
    total_number++;
}

Pumpkin::~Pumpkin() {
    total_weight -= weight;
    total_number--;
}

void Pumpkin::display() {
    std::cout << "This one weights " << weight << std::endl;
}

void Pumpkin::total_display() {
    std::cout << "Total weight of " << total_number << " pumkins is " << total_weight << std::endl;
}