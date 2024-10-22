#include <stdio.h>

void escape(char[], char[]);

int main()
{
    char sentence[100], to[100], c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        sentence[i++] = c;
    }
    sentence[i] = '\0';

    escape(sentence, to);

    printf("%s", to);
    return 0;
}

void escape(char from[], char to[])
{
    for (int i = 0, j = 0; from[i] != '\0'; i++, j++)
    {
        switch (from[i])
        {
        case '\n':
            to[j] = '\\';
            j++;
            to[j] = 'n';
            break;
        case '\t':
            to[j] = '\\';
            j++;
            to[j] = 't';
            break;
        default:
            to[j] = from[i];
            break;
        }
        printf(" %d-%d ", i, j);
        // to[i] = from[i];
    }
}
