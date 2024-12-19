#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
	int length = strlen(str);
	for (int i = 0; i < length / 2; i++) {
		char tmp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = tmp;
	}
}

void reverse_recursive(char str[], int i) {
	int length = strlen(str);
	if (i > length / 2) {
		return;
	}

	char tmp = str[i];
	str[i] = str[length - i - 1];
	str[length - i - 1] = tmp;

	reverse_recursive(str, ++i);
}

void reverse_recursive_v2(char str[], int start, int end) {
	int length = strlen(str);
	if (start > end) {
		return;
	}

	char tmp = str[start];
	str[start] = str[end];
	str[end] = tmp;

	reverse_recursive_v2(str, start + 1, end - 1);
}

int main(void) {

	char str[] = "hello0";
	reverse_recursive_v2(str, 0, strlen(str)-1);

	for (int i = 0; i < strlen(str); i++) {
		printf("%c ", str[i]);
	}

	return 0;
}
