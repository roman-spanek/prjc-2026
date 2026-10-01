#include "calculations.h"
#include "math_tools.h"
#include <stdio.h>

// --- Static counters (local to this file) ---
static int circle_calls = 0;
static int square_calls = 0;

// --- Static helper for debug output ---
static void print_debug_stats(void) {
#ifdef DEBUG
    printf("[DEBUG] circle_area() called %d times\n", circle_calls);
    printf("[DEBUG] square_area() called %d times\n", square_calls);
#endif
}

// --- Public methods ---
void calculate_and_print_circle(double radius) {
    double area = circle_area(radius);
    printf("Circle radius: %.2f, area: %.2f\n", radius, area);
    circle_calls++;
    print_debug_stats();
}

void calculate_and_print_square(double side) {
    double area = square_area(side);
    printf("Square side: %.2f, area: %.2f\n", side, area);
    square_calls++;
    print_debug_stats();
}