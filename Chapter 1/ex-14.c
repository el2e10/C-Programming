#include <stdio.h>

#define COUNT_LENGTH 26

int get_sentence(char[]);
void initialize(int[]);
void draw_histogram(int[]);
char to_lower(int);

int main()
{
	char sentence[100], sentence_length = 0, tmp_word[100];
	int count[COUNT_LENGTH], position;
	// position = to_lower('D') - 97;
	// printf("%d %d", position, to_lower('D'));
	sentence_length = get_sentence(sentence);
	for (int i = 0; i <= sentence_length; i++)
	{
		if (sentence[i] != ' ' && sentence[i] != '\0')
		{
			char c = to_lower(sentence[i]);
			position = c - 97;
			// printf("%c %d %d\n", c, c, position);
			count[position] = count[position] + 1;
		}
	}
	draw_histogram(count);
	return 0;
}

char to_lower(int c)
{
	if (c >= 65 && c <= 90)
		return c + 32;
	return c;
}

void draw_histogram(int array[])
{
	int count, length;
	for (int i = 0; i < COUNT_LENGTH; i++)
	{
		length = i;
		count = array[i];
		if (count == 0)
			continue;
		printf("%c-|", length + 97);
		for (int j = 0; j < count; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void initialize(int count[])
{
	for (int i = 0; i < COUNT_LENGTH; i++)
	{
		count[i] = 0;
	}
}

int get_sentence(char sentence[])
{
	int c, i = 0;
	while ((c = getchar()) != '\n')
	{
		sentence[i] = c;
		i += 1;
	}
	sentence[i] = '\0';
	return i;
}
