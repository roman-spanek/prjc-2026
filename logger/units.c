#include "units.h"

float celsius_to_fahrenheit(float celsius){
    return celsius * 9.0f / 5.0f + 32.0f;
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15f;
}