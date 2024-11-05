#include <stdio.h>
#include <string.h>

int strindex(char[], char[]);

int main() {

  char source[] = "Helollosfafl ok";
  char target[] = "l  o";

  int starting_location = strindex(source, target);
  printf("The starting index is %d\n", starting_location);
  return 0;
}

int strindex(char s[], char t[]) {
  int source_length = strlen(s);
  int target_length = strlen(t);
  int start_index = -1;

  for (int i = source_length - 1, j = target_length - 1; i >= 0; i--) {
    if (s[i] == t[j]) {
      if (j == 0) {
        start_index = i + target_length - 1;
        break;
      }
      j--;
    } else {
      if (j < target_length - 1) {
        i++;
      }
      j = target_length - 1;
      start_index = -1;
    }
  }

  return start_index;
}
