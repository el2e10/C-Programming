#include <stdio.h>

/*
Programe to copy inputs to its outputs, replacing each char of one or more blanks by a single
blank.
*/

int main()
{

    int cur, prev;
    while ((cur = getchar()) != EOF)
    {
        if (prev == ' ' && cur == ' ')
            ;
        else
        {
            putchar(cur);
        }
        prev = cur;
    }
    return 0;
}