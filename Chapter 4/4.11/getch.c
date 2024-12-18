#include "calc.h"
#include <stdio.h>

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void) { return getchar(); }

void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters \n");
	} else {
		buf[bufp++] = c;
	}
}
