//
// Created by roman on 01/12/2025.
//

#ifndef PR10_VIRTUAL_SHAPES_NO_VIRTUAL_H
#define PR10_VIRTUAL_SHAPES_NO_VIRTUAL_H
class Shape_no_virtual {
public:
    // Regular virtual method (optional override)
    void info();
    // Pure virtual method = MUST be overridden in derived classes
    virtual double area() const = 0;

    // Always give a virtual destructor when using polymorphism
    virtual ~Shape_no_virtual();
};
class Circle_no_virtual : public Shape_no_virtual {
    double r;
public:
    Circle_no_virtual(double radius);

    // Override optional virtual method - we need to remove - not use override
    void info();

    // Must implement pure virtual method
    double area() const override;
};

// ---------------------------
// Derived class: Rectangle
// ---------------------------
class Rectangle_no_virtual : public Shape_no_virtual {
    double w, h;

public:
    Rectangle_no_virtual(double width, double height);

    // Optionally override virtual method - we need to remove - not use override
    void info();

    // Must implement pure virtual method
    double area() const override;
};

#endif //PR10_VIRTUAL_SHAPES_NO_VIRTUAL_H