#include <stdio.h>

void expand(char[], char[]);
int main()
{
    char c, from[100], to[100];
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        from[i++] = c;
    }
    from[i] = '\0';
    expand(from, to);
    printf("%s", to);
    return 0;
}

void expand(char from[], char to[])
{
    char lower = '$', upper = '$', current;
    for (int i = 0; from[i] != '\0'; i++)
    {
        current = from[i];
        if (current == '-')
        {
            continue;
        }
        if (lower == '$')
        {
            lower = current;
        }
        else if (upper == '$')
        {
            upper = current;
        }
    }
    // printf("%d %c %d %d\n", lower, lower + 1, upper);
    for (int i = lower; i <= upper; i++)
    {
        printf("%c\n", i);
    }
}