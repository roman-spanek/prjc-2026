#include <stdio.h>
#include "config.h"
#include "units.h"
#include "stats.h"

/* converts a value from Celsius to the unit chosen at compile time */
static float convert(float celsius)
{
#if OUTPUT_UNIT == UNIT_F
    return celsius_to_fahrenheit(celsius);
#elif OUTPUT_UNIT == UNIT_K
    return celsius_to_kelvin(celsius);
#else
    return celsius;
#endif
}

int main(void) {
    float value;
    stats_reset();
    LOG("program started");
    while (scanf("%f", &value) == 1) {
        if (IN_RANGE(value, MIN_VALID_TEMP, MAX_VALID_TEMP)) {
            stats_add(value);
            LOG("value accepted");
        } else {
            printf("Warning: %.2f is out of range, ignored\n", value);
        }
    }

    if (stats_count() == 0) {
        printf("No valid measurements.\n");
        return 1;
    }

    printf("Count:   %d\n", stats_count());
    printf("Minimum: %.2f %s\n", convert(stats_min()), UNIT_LABEL);
    printf("Maximum: %.2f %s\n", convert(stats_max()), UNIT_LABEL);
    printf("Average: %.2f %s\n", convert(stats_average()), UNIT_LABEL);

    return 0;
}