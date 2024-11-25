#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 100
#define NUMBER '0'

int sp = 0, input_index = 0;
int stack[INPUT_SIZE];

char gettop(char[]);
int pop();
void push(int);

void print_array(char s[]) {
	for (int i = 0; s[i] != '\0'; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
}

int main() {
	char input[INPUT_SIZE] = "-10 -5 + 20 * -2 /";
	char number[INPUT_SIZE];
	char c;

	while ((c = gettop(input)) != '\0') {
		int result;
		int op2, op1;
		switch (c) {
			int i = 0;
		case NUMBER:
			for (i = 0; input[input_index] != ' ' && input[input_index] != '\0';
				 i++, input_index++) {
				number[i] = input[input_index];
			}
			number[i] = '\0';
			push(atoi(number));
			break;
		case '+':
			op2 = pop();
			op1 = pop();
			result = op1 + op2;
			push(result);
			break;
		case '-':
			op2 = pop();
			op1 = pop();
			result = op1 - op2;
			printf("%d %d", op2, op1);
			push(result);
			break;
		case '*':
			op2 = pop();
			op1 = pop();
			result = op2 * op1;
			push(result);
			break;
		case '/':
			op2 = pop();
			result = pop() / op2;
			push(result);
			break;
		case '%':
			op2 = pop();
			result = pop() % op2;
			push(result);
			printf("Modulus operator %d %d\n", op2, result);
			break;
		}
	}
	printf("The final result of stack is %d\n", stack[0]);
	return 0;
}

void push(int s) {

	if (isdigit(s)) {
		stack[sp++] = s - '0';
	} else {
		stack[sp++] = s;
	}
}

int pop() { return stack[--sp]; }

char gettop(char s[]) {
	if (isdigit(s[input_index])) {
		return NUMBER;
	} else if (s[input_index] == '-' && s[input_index + 1] != ' ' && s[input_index + 1] != '\0') {
		return NUMBER;
	} else {
		return s[input_index++];
	}
}
