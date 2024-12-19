#include <stdio.h>

#define swap_v2(t, x, y)                                                       \
	t tmp = x;                                                                 \
	x = y;                                                                     \
	y = tmp;

#define sum(a, b) a + b

void swap_v1(char x, char y) {

	x = x ^ y;
	y = x ^ y;
	x = x ^ y;

	printf("%c %c\n", x, y);
}

int main(void) {

	int a = 'a', b = 'c';
	printf("%c %c\n", a, b);
	swap_v2(char, a, b);

	printf("%c %c\n", a, b);
}
