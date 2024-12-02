#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 100
#define NUMBER '0'
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VAR '4'

int sp = 0, input_index = 0;
int stack[INPUT_SIZE];
int dup_stack[INPUT_SIZE];

char gettop(char[]);
int pop();
void push(int);

void print_array(int *s) {
	for (int i = 0; s[i] != '\0'; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
}

void print_stack(void) {
	if (sp <= 0) {
		printf("[]\n");
		return;
	}
	int i;
	printf("[");
	for (i = 0; i < sp; i++) {
		if (i == sp - 1) {
			printf("%d]\n", stack[i]);
		} else {
			printf("%d, ", stack[i]);
		}
	}
}

void swap_top(void) {
	if (sp < 2) {
		return;
	}
	int tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void duplicate_stack(int *dup_stack) {
	int i;
	for (i = 0; i < sp; i++) {
		dup_stack[i] = stack[i];
	}
}

void clear_stack(void) {
	for (int i = sp; i > 0; --i) {
		pop();
	}
}

void ungets(char input[], char new[]) {
	int input_len = strlen(input), new_len = strlen(new), i;
	if (INPUT_SIZE < input_len + new_len) {
		return;
	}

	for (i = 0; i < new_len; i++) {
		input[input_len + i] = new[i];
	}

	input[input_len + i] = '\0';
}

int main(void) {
	int valid_expression = 1;
	char input[INPUT_SIZE] = "3 8 ";
	char number[INPUT_SIZE];
	char c;

	ungets(input, "9 3 - + +");

	while ((c = gettop(input)) != '\0' && valid_expression) {
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
			break;
		case SIN:
			push(sin(pop()));
			printf("sin function detected\n");
			break;
		case POW:
			op2 = pop();
			op1 = pop();
			push(pow(op2, op1));
			printf("pow function detected\n");
			break;
		case EXP:
			push(exp(pop()));
			printf("exp function detected\n");
			break;
		case VAR:
			/*
			 * We just replace the variable with the top element in stack
			 * */
			if (sp == 0) {
				printf("Invalid expression\n");
				valid_expression = 0;
				break;
			}
			push(stack[sp - 1]);
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

int pop(void) { return stack[--sp]; }

char gettop(char s[]) {
	if (isdigit(s[input_index])) {
		return NUMBER;
	} else if (s[input_index] == '-' && s[input_index + 1] != ' ' &&
			   s[input_index + 1] != '\0') {
		return NUMBER;
	} else if (s[input_index] == 's' && s[input_index + 1] == 'i' &&
			   s[input_index + 2] == 'n') {
		input_index += 3;
		return SIN;
	} else if (s[input_index] == 'e' && s[input_index + 1] == 'x' &&
			   s[input_index + 2] == 'p') {
		input_index += 3;
		return EXP;
	} else if (s[input_index] == 'p' && s[input_index + 1] == 'o' &&
			   s[input_index + 2] == 'w') {
		input_index += 3;
		return POW;
	} else if (isalpha(s[input_index])) {
		input_index++;
		return VAR;
	} else {
		return s[input_index++];
	}
}
