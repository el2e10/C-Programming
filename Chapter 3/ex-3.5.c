#include <stdio.h>

void read_integer() {}

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

void print_array(char arr[]) {

  for (int i = 0; arr[i] != '\0'; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
}

void itob(int n, char s[], int base) {

  int tmp_n = n, i, s_index = 0;
  char ascii_table[16];

  for (i = 0; i <= 9; i++)
    ascii_table[i] = i + '0';
  for (int j = 0; j < 6; i++, j++)
    ascii_table[i] = j + 'A';

  do {
    s[s_index++] = ascii_table[tmp_n % base];
  } while ((tmp_n /= base) > 0);
  ascii_table[s_index] = '\0';

  reverse(s);
  print_array(s);
}

int main() {
  char result[100];
  int val = 2888;

  itob(val, result, 16);

  return 0;
}
