#include <stdio.h>

#define COUNT_LENGTH 10 + 1

int get_sentence(char[]);
void initialize(int[]);
void draw_histogram(int[]);

int main()
{
	char sentence[100], sentence_length = 0, tmp_word[100];
	int count[COUNT_LENGTH], past_index = 0;
	initialize(count); // Initializing the count array to zeros

	sentence_length = get_sentence(sentence);
	for (int i = 0; i <= sentence_length; i++)
	{
		if (sentence[i] == ' ' || sentence[i] == '\0')
		{
			int word_length = i - past_index;
			count[word_length] = count[word_length] + 1;
			past_index = i + 1;
		}
	}
	draw_histogram(count);
	return 0;
}

void draw_histogram(int array[])
{
	// lenght is the word length and count is the number of words with a particular length
	int count, length;
	for (int i = 0; i < COUNT_LENGTH; i++)
	{
		length = i;
		count = array[i];
		if (count == 0)
			continue;
		printf("%d -|", length);
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
