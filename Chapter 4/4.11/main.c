#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

int getop(char[]);
void push(double);
double pop(void);

int main(void) {
	int type;
	double op2;
	float val;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) {
				push(pop() / op2);
			} else {
				printf("error: zero division\n");
			}
			break;
		case '\n':
			val = pop();
			printf("The output is %.2g \n", val);
			break;
		default:
			printf("error: unkonw command %s\n", s);
			break;
		}
	}

	return 0;
}

