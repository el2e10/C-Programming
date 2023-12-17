#include <stdio.h>

/*
Program to count the number of words
*/

int main()
{
    int c;
    int word_count;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            word_count++;
        }
    }
    printf("The number of words are %d\n", word_count);
    return 0;
}