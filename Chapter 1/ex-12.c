#include <stdio.h>

/*
Program to count the number of words
*/

int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
        {
            putchar('\n');
        }
        else
        {

            printf('%d', c);
            ptchar(c);
        }
    }
    return 0;
}