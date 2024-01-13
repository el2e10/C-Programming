#include <stdio.h>

#define MAX_LENGTH 10
#define ARRAY_SIZE 200

int get_sentence(char[]);
void print_sentence(char[], int, int);

int main()
{
    char sentence[ARRAY_SIZE], c;
    int past_line_start = 0;
    get_sentence(sentence);
    for (int i = 0; (c = sentence[i]) != '\0'; i++)
    {
        if (c == '\n')
        {
            // printf("%d %d", past_line_start, i);
            if (i - past_line_start >= MAX_LENGTH)
            {

                print_sentence(sentence, past_line_start, i);
            }
            past_line_start = i;
        }
    }
}

void print_sentence(char sentence[], int start, int end)
{
    for (int i = start; i < end; i++)
    {
        printf("%c", sentence[i]);
    }
    // printf("\n");
}

int get_sentence(char sentence[])
{
    int c, i = 0;
    while ((c = getchar()) != EOF)
    {
        sentence[i] = c;
        i += 1;
    }
    sentence[i] = '\0';
    return i;
}