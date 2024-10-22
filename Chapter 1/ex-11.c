#include <stdio.h>

/*
Program to count the number of words
*/

int main() {
  int c;
  int word_count;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      word_count++;
    }
  }

  printf("The word count is %d", word_count);
  return 0;
}
