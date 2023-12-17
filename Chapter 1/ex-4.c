#include <stdio.h>

/*
Exercise 1.4
Program for converting celcius to farenheit
*/

int main()
{
    float cels, fahr;
    int lower = 0, upper = 320, step = 20;

    cels = lower;
    printf("Celsius to Fahrenheit table\n");
    while (cels <= upper)
    {
        fahr = (cels * (9.0 / 5.0)) + 32;
        printf("%6.2f°C -> %6.2f°F\n", cels, fahr);
        cels += step;
    }

    return 0;
}