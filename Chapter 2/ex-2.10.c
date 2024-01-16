#include <stdio.h>
#include <string.h>

void lower(char[]);

int main()
{
    char str[] = "A3PLE";
    lower(str);
    printf("%s\n", str);
    return 0;
}

void lower(char str[])
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        char c = str[i];
        char lower = (c >= 'A' && c <= 'Z') ? c + 32 : c;
        str[i] = lower;
    }
}