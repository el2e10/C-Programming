#include "calc.h"
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
	int i, c;
	static int buf[1];
	static int bufp = 0;

	if (bufp > 0) {
		c = buf[--bufp];
	} else {
		c = getch();
	}
	while ((s[0] = c) == ' ' || c == '\t') {
		c = getch();
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch())) {
		}
	if (c == '.')
		while (isdigit(s[++i] = c = getch())) {
		}
	buf[bufp++] = c;
	s[i] = '\0';

	return NUMBER;
}
