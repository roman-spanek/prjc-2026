#include "stats.h"

/* module state, invisible outside this file */
static int count = 0;
static float sum = 0.0f;
static float min_value = 0.0f;
static float max_value = 0.0f;

void stats_reset(void) {
    count = 0;
    sum = 0.0f;
    min_value = 0.0f;
    max_value = 0.0f;
}

void stats_add(float value) {
    if (count == 0) {
        min_value = value;
        max_value = value;
    } else {
        if (value < min_value) min_value = value;
        if (value > max_value) max_value = value;
    }
    sum += value;
    count++;
}

int stats_count(void)  { return count; }
float stats_min(void)  { return min_value; }
float stats_max(void)  { return max_value; }

float stats_average(void){
    if (count == 0) {
        return 0.0f;
    }
    return sum / count;
}