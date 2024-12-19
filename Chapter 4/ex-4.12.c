#include <stdio.h>
#include <string.h>

char arr[100];
int arrp = 0;

void printd(int num) {
	if (num < 0) {
		arr[arrp++] = '-';
		num = -num;
	}

	int num2 = num % 10;
	num = num / 10;

	if (num > 0) {
		printd(num);
	} else {
		arr[arrp] = '\0';
	}
	arr[arrp++] = num % 10 + '0';
}

int main(void) {
	int num = 2324429;
	printd(num);
	for (int i = 0; i < strlen(arr); i++) {
		printf("%c", arr[i]);
	}
	printf("\n");
	return 0;
}
