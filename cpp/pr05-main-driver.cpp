#include "Pumpkin.h"
#include <iostream>
using namespace std;

int main() {
    Pumpkin p1(15), p2(20), p3(45);
    Pumpkin *p_pumpkin = new Pumpkin(1);
    p1.display();
    p2.display();
    p3.display();
    p_pumpkin->display();

    Pumpkin::total_display();
    p1.total_display();

    delete(p_pumpkin);
    //do not need to call destructor explicitly on object p1, p2, p3
    //as those are local objects and will be destroyed automatically
    //when they go out of scope at the end of main() function.

    Pumpkin::total_display();
    p1.total_display();
}