#include <stdio.h>

#define ARRAY_SIZE 100

void get_sentence(char[]);
void remove_blank(char[], char[]);

int main()
{
    char sentence[ARRAY_SIZE], current_line[ARRAY_SIZE];
    int current_line_index = 0;
    get_sentence(sentence);

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        current_line[current_line_index] = sentence[i];
        current_line_index += 1;

        if (sentence[i] == '\n')
        {
            char clean_line[ARRAY_SIZE] = {};
            current_line[current_line_index] = '\0';
            remove_blank(current_line, clean_line);
            current_line_index = 0;
            printf("The clean line is %s\n", clean_line);
        }
    }
    return 0;
}

void remove_blank(char line[], char clean_line[])
{
    int start_index = 0, end_index;

    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
        {
            if (start_index == 0)
            {
                start_index = i;
            }
            end_index = i;
        }
    }
    for (int i = start_index, j = 0; i <= end_index; i++, j++)
    {
        clean_line[j] = line[i];
    }
}

void get_sentence(char sentence[])
{
    int c, i = 0;
    while ((c = getchar()) != EOF)
    {
        sentence[i] = c;
        i++;
    }
    sentence[i] = '\0';
}