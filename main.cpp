#include <iostream>

#include "shapes.h"
#include "shapes-no-virtual.h"
#include "template.h"

int main() {

    //1. without virtual
    //if we call method using pointer of base class, it calls base class method even if derived class has its own implementation
    Shape_no_virtual *s1_no_virtual = new Circle_no_virtual(5.0);
    Shape_no_virtual *s2_no_virtual = new Rectangle_no_virtual(4.0, 6.0);

    s1_no_virtual->info(); // Calls Shape_no_virtual::info() even if Circle_no_virtual has its own info() method definition
    std::cout << "Area: " << s1_no_virtual->area() << "\n\n";

    s2_no_virtual->info(); // Calls Shape_no_virtual::info() even if Circle_no_virtual has its own info() method definition
    std::cout << "Area: " << s2_no_virtual->area() << "\n\n";

    delete s1_no_virtual;
    delete s2_no_virtual;


    // template class
    // 1. template classes
    Element element(10);
    std::cout << element.value() << std::endl;

    int a = 10, b = 20;
    float fa = 10.20, fb = 20.20;
    std::cout << max(a, b) << std::endl;
    std::cout << max(fa, fb) << std::endl;

    return 0;


/*
    //2. with virtual
    //no polymorphism happens, it calls derived class methods
    Shape *s1 = new Circle(5.0);
    Shape *s2 = new Rectangle(4.0, 6.0);

    s1->info(); // Calls Circle::info()
    std::cout << "Area: " << s1->area() << "\n\n"; //correctly calls Circle::area() which overrides Shape::area()

    s2->info(); // Calls Rectangle::info()
    std::cout << "Area: " << s2->area() << "\n\n"; //correctly calls Rectangle::area() which overrides Shape::area()

    delete s1;
    delete s2;

    return 0;
*/
}
/*
 output:
I am a generic shape.
Area: 78.5397

I am a generic shape.
Area: 24

I am a circle.
Area: 78.5397

I am a rectangle.
Area: 24

*/