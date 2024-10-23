#include <stdio.h>
#include <string.h>

void expand(char[], char[]);
void generate(char, char, char[]);
void print_array(char[]);

int main() {

  char c, from[100], to[100];
  int i = 0;

  while ((c = getchar()) != '\n') {
    from[i++] = c;
  }
  from[i] = '\0';
  to[0] = '\0';

  expand(from, to);

  print_array(to);
  return 0;
}

void expand(char from[], char to[]) {
  char lower = '$', upper = '$', current;

  printf("The sequence is\n");
  for (int i = 0; from[i] != '\0'; i++) {

    for (; from[i] != '-'; i++)
      ;
    if (i > 0)
      lower = from[i - 1];
    else
      lower = from[i + 1];
    upper = from[++i];

    generate(lower, upper, to);
  }
  printf("\n");
}

void generate(char lower, char upper, char to[]) {

  int end_index;
  for (end_index = 0; to[end_index] != '\0'; end_index++)
    ;

  for (int i = lower; i <= upper; i++) {
    // printf("%d %d %d %d %d\n", end_index > 0, end_index, to[end_index-1] ==
    // i, to[end_index-1], i);
    if (end_index > 0 && to[end_index - 1] == i) {
      continue;
    }

    to[end_index] = i;
    end_index++;
    printf("%c, ", i);
  }
  to[end_index + 1] = '\n';
}

void print_array(char arr[]) {
  for (int i = 0; arr[i] != '\0'; i++) {
    printf("%c, ", arr[i]);
  }
}
