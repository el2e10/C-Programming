#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(char arr[]) {

  for (int i = 0; arr[i] != '\0'; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
}

void reverse(char arr[]) {
  int arr_len = 0;
  for (; arr[arr_len] != '\0'; arr_len++)
    ;

  char tmp;
  for (int i = 0; i <= arr_len / 2; i++) {
    tmp = arr[i];
    arr[i] = arr[arr_len - i - 1];
    arr[arr_len - i - 1] = tmp;
  }
  arr[arr_len] = '\0';
}

void itoa(long n, char s[]) {

  long sign;
  int i = 0, correction = 0;

  if ((sign = n) == LONG_MIN) {
    correction = 1;
    n = (n + 1) * -1;
  } else if ((sign = n) < 0) {
    n *= -1;
  }

  do {
    char l = n % 10 + '0';
    s[i++] = l;
    // printf("%c\n", l);
  } while ((n /= 10) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[0] = s[0] + correction;

  s[i] = '\0';
}

int main() {
  char c[100], d;
  long j = 1 * pow(2, 13);
  printf("Converting %ld to string: \n", j);

  itoa(j, c);

  reverse(c);
  print_array(c);

  return 0;
}
