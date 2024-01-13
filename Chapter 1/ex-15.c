#include <stdio.h>

int convert_temp(float);
int main()
{

	float cel, fahr;
	int lower = 0, upper = 320, step = 20;
	fahr = lower;

	printf("Fahrenheit to Celsius table\n");
	while (fahr <= upper)
	{
		cel = convert_temp(fahr);
		printf("%6.2f°F -> %6.2f°C\n", fahr, cel);
		fahr += step;
	}
	return 0;
}

int convert_temp(float fahr)
{
	return (fahr - 32) * 5.0 / 9.0;
}
