#include "math_tools.h"
#include <math.h>

// Static helper function, not shared outside this file
static double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; ++i)
        result *= base;
    return result;
}

// Public functions (extern by default since declared in header)
double circle_area(double radius) {
    if (radius < 0) {
        DEBUG_MSG("square_area called with negative side", radius);
        return 0.0;
    }
    DEBUG_MSG("square_area called with side", radius);
    double area = M_PI * power(radius, 2);
    printf("circle_area(%.2f) = %.2f \n", radius, area); // <-- all good here?
    return area;
}

double square_area(double side) {
    if (side < 0) {
        DEBUG_MSG("square_area called with negative side", side);
        return 0.0;
    }
    DEBUG_MSG("square_area called with side", side);
    double area = power(side, 2);
    printf("square_area(%.2f) = %.2f \n", side, area); // <-- all good here?
    return area;
}