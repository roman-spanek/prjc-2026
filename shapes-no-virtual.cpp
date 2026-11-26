#include "shapes-no-virtual.h"

#include <iostream>
// ---------------------------
// Abstract base class
// ---------------------------
// Regular virtual method (optional override)
void Shape_no_virtual::info() {
    std::cout << "I am a generic shape.\n";
}
// Always give a virtual destructor when using polymorphism
Shape_no_virtual::~Shape_no_virtual() {
}
Circle_no_virtual::Circle_no_virtual(double radius) : r(radius) {
}
void Circle_no_virtual::info() {
    std::cout << "I am a circle.\n";
}

double Circle_no_virtual::area() const {
    return 3.14159 * r * r;
}
Rectangle_no_virtual::Rectangle_no_virtual(double width, double height) : w(width), h(height) {
}
void Rectangle_no_virtual::info() {
    std::cout << "I am a rectangle.\n";
}

// Must implement pure virtual method
double Rectangle_no_virtual::area() const {
    return w * h;
}

