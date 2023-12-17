#include <stdio.h>

/*
Exercise 1.3
Adding a heading to the top of the program
*/

int main()
{
    float cels, fahr;
    int lower = 0, upper = 320, step = 20;

    fahr = lower;
    printf("Fahrenheit to Celsius table\n");
    while (fahr <= upper)
    {
        cels = (fahr - 32) * 5.0 / 9.0;
        printf("%6.2f°F -> %6.2f°C\n", fahr, cels);
        fahr += step;
    }

    return 0;
}