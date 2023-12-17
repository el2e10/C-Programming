#include <stdio.h>

/*
Programe to count newline, tabs and blanks
*/

int main()
{
    int count = 0;
    int character;

    while ((character = getchar()) != EOF)
    {
        if (character == '\n' || character == '\t' || character == ' ')
        {
            ++count;
        }
    }
    printf("The total count of newlines, tabs and blanks are %d", count);
    return 0;
}