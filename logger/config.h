#ifndef CONFIG_H
#define CONFIG_H

#define MIN_VALID_TEMP -90.0f
#define MAX_VALID_TEMP 60.0f

/* returns 1 if x lies in <lo, hi> */
#define IN_RANGE(x, lo, hi) ((x) >= (lo) && (x) <= (hi))

/* output unit selection */
#define UNIT_C 1
#define UNIT_F 2
#define UNIT_K 3

#ifndef OUTPUT_UNIT
#define OUTPUT_UNIT UNIT_C
#endif

#if OUTPUT_UNIT == UNIT_C
    #define UNIT_LABEL "C"
#elif OUTPUT_UNIT == UNIT_F
    #define UNIT_LABEL "F"
#elif OUTPUT_UNIT == UNIT_K
    #define UNIT_LABEL "K"
#else
    #error "Unknown OUTPUT_UNIT (use UNIT_C, UNIT_F or UNIT_K)"
#endif

/* debug logging, compiled in only with -DDEBUG */
#ifdef DEBUG
    #include <stdio.h>
    #define LOG(msg) printf("[DEBUG %s:%d] %s\n", __FILE__, __LINE__, msg)
#else
    #define LOG(msg)
#endif

#endif