#include <stdio.h>

/*
Program to replace tab by \t, backspace by \b and backslash by \\
*/

int main()
{

    int text;
    while ((text = getchar()) != EOF)
    {
        if (text == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        if (text == '\n')
        {
            putchar('\\');
            putchar('n');
        }
        if (text == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        if (text != '\\' && text != '\t' && text != '\n')
        {
            putchar(text);
        }
    }
    return 0;
}