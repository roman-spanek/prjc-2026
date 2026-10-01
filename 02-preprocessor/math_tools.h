#ifndef MATH_TOOLS_H
#define MATH_TOOLS_H

#include <stdio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define DEBUG

#ifdef DEBUG
#define DEBUG_MSG(msg, val) \
printf("[DEBUG] %s: %.4f\n", msg, (double)(val))
#else
#define DEBUG_MSG(msg, val)
#endif

// --- Public function declarations ---
extern double circle_area(double radius);
extern double square_area(double side);

#endif