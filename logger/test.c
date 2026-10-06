/*
#include <stdio.h>
#include "units.h"
#include "stats.h"

static int passed = 0;
static int failed = 0;

#define CHECK(expr) do { \
if (expr) { \
passed++; \
} else { \
failed++; \
printf("FAILED %s:%d: %s\n", __FILE__, __LINE__, #expr); \
} \
} while (0)

#define NEAR(a, b) (((a) - (b)) < 0.001f && ((b) - (a)) < 0.001f)

static void test_units(void)
{
    CHECK(NEAR(celsius_to_fahrenheit(100.0f), 212.0f));
    CHECK(NEAR(celsius_to_fahrenheit(0.0f), 32.0f));
    CHECK(NEAR(celsius_to_kelvin(0.0f), 273.15f));
}

static void test_stats(void)
{
    stats_reset();
    CHECK(stats_count() == 0);
    CHECK(NEAR(stats_average(), 0.0f));

    stats_add(10.0f);
    stats_add(20.0f);
    stats_add(30.0f);
    CHECK(stats_count() == 3);
    CHECK(NEAR(stats_min(), 10.0f));
    CHECK(NEAR(stats_max(), 30.0f));
    CHECK(NEAR(stats_average(), 20.0f));

    stats_reset();
    CHECK(stats_count() == 0);
}

int main2(void)
{
    test_units();
    test_stats();

    printf("Passed: %d, failed: %d\n", passed, failed);
    return failed == 0 ? 0 : 1;
}
*/