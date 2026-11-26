//
// Created by roman on 27/11/2025.
//

#ifndef PR10_VIRTUAL_SHAPES_H
#define PR10_VIRTUAL_SHAPES_H
#include <iostream>

// ---------------------------
// Abstract base class
// ---------------------------
class Shape {
public:
    // Regular virtual method (optional override)
    virtual void info();

    // Pure virtual method = MUST be overridden in derived classes
    virtual double area() const = 0;

    // Always give a virtual destructor when using polymorphism
    virtual ~Shape();
};

// ---------------------------
// Derived class: Circle
// ---------------------------
class Circle : public Shape {
    double r;

public:
    Circle(double radius);

    // Override optional virtual method
    void info() override;

    // Must implement pure virtual method
    double area() const override;
};

// ---------------------------
// Derived class: Rectangle
// ---------------------------
class Rectangle : public Shape {
    double w, h;

public:
    Rectangle(double width, double height);

    // Optionally override virtual method
    void info() override;

    // Must implement pure virtual method
    double area() const override;
};

#endif //PR10_VIRTUAL_SHAPES_H