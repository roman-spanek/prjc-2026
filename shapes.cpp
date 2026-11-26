#include "shapes.h"

#include <iostream>

// ---------------------------
// Abstract base class
// ---------------------------
   // Regular virtual method (optional override)
    void Shape::info() {
        std::cout << "I am a generic shape.\n";
    }

    // Always give a virtual destructor when using polymorphism
    Shape::~Shape() {}


// ---------------------------
// Derived class: Circle
// ---------------------------
    Circle::Circle(double radius) : r(radius) {}

    // Override optional virtual method
    void Circle::info() {
        std::cout << "I am a circle.\n";
    }

    // Must implement pure virtual method
    double Circle::area() const {
        return 3.14159 * r * r;
    }


    Rectangle::Rectangle(double width, double height) : w(width), h(height) {}

    // Optionally override virtual method
    void Rectangle::info() {
        std::cout << "I am a rectangle.\n";
    }

    // Must implement pure virtual method
    double Rectangle::area() const {
        return w * h;
    }


