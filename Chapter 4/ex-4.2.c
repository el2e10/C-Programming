#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {

  char s[] = "-12334242.4890e8";
  double result, atof(char[]);

  result = atof(s);
  printf("The output is %.24lf\n", result);
  return 0;
}

double atof(char s[]) {
  double output = 0.0, fraction = 0.0, sign = 1, power_size = 0;
  int length = strlen(s), atoi(char), i = 0, fraction_size = 1;

  if (s[0] == '-') {
    sign = -1;
    i++;
  }

  for (; isdigit(s[i]); i++) {
    output = 10.0 * output + atoi(s[i]);
  }

  if (s[i] == '.')
    i++;

  for (; isdigit(s[i]); i++, fraction_size *= 10) {
    output = 10.0 * output + atoi(s[i]);
  }

  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    int power_sign = 1;
    if (s[i] == '-') {
      power_sign = -1;
      i++;
    }
    if (s[i] == '+') {
      power_sign = 1;
      i++;
    }
    for (; isdigit(s[i]); i++) {
      power_size = 10.0 * power_size + atoi(s[i]);
    }
    output = (power_sign == -1) ? output * 1 / pow(10.0, power_size)
                                : output * pow(10.0, power_size);
  }
  printf("%lf %lf\n", power_size, output);

  return (output / fraction_size) * sign;
}

int atoi(char c) { return c - '0'; }
