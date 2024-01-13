#include <stdio.h>

#define MAX_LENGTH 7

int get_line(char[], int);
void copy(char[], char[]);

int main()
{

	int max_length = 0, current_length = 0;
	char current_sentence[MAX_LENGTH], longest_sentence[MAX_LENGTH];
	while ((current_length = get_line(current_sentence, MAX_LENGTH)) > 0)
	{
		if (current_length > max_length)
		{
			max_length = current_length;
			copy(current_sentence, longest_sentence);
		}
	}
	printf("The longest sentence is %s... with length %d\n", longest_sentence, max_length);
	return 0;
}

void copy(char from[], char to[])
{
	for (int i = 0; from[i] != '\0'; i++)
	{
		to[i] = from[i];
	}
}

int get_line(char sentence[], int max_length)
{

	int c, i = 0;
	while ((c = getchar()) != EOF && c != '\n')
	{
		if (i < max_length - 1)
		{
			sentence[i] = c;
		}
		i++;
	}
	sentence[i] = '\0';
	return i;
}
