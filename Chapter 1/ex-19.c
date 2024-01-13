#include <stdio.h>

#define ARRAY_SIZE 200

int get_sentence(char[]);
void reverse(char[], int);

int main()
{
    char sentence[ARRAY_SIZE], c;
    int past_line_start = 0;
    int length = get_sentence(sentence);
    reverse(sentence, length);
}

void reverse(char sentence[], int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        char tmp = sentence[i];
        sentence[i] = sentence[length - i - 1];
        sentence[length - i - 1] = tmp;
    }
    printf("The reversed sentence is %s", sentence);
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