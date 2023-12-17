#include <stdio.h>

/*
Exercise 1.5
Program for converting celcius to farenheit
The program will convert 300C to 0C
*/

int main()
{
    float cels, fahr;
    int lower = 0, upper = 300, step = 20;

    cels = lower;
    printf("Celsius to Fahrenheit table\n");

    for (cels = upper; cels >= lower; cels -= step)
    {
        fahr = (cels * 9.0 / 5.0) + 32;
        printf("%5.1f°C -> %5.1f°F\n", cels, fahr);
    }

    return 0;
}