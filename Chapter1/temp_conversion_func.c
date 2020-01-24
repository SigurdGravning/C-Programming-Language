#include<stdio.h>

float CelsiusToFahr(float celsius);
float FahrToCelsius(float fahr);

void main() {
    float i;

    printf("Conversion table for Celsius to Fahrenheit\n");

    for (i = 0; i <= 100; i += 5) {
        printf("%3.0f C\t%6.1f F\n", i, CelsiusToFahr(i));
    }

    printf("Conversion table for Fahrenheit to Celsius\n");

    for (i = 0; i <= 300; i += 20) {
        printf("%3.0f F\t%3.1f C\n", i, FahrToCelsius(i));
    }
}

float CelsiusToFahr(float celsius) {
    return (9.0/5.0) * celsius + 32.0;
}

float FahrToCelsius(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}