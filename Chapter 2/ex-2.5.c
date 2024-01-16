#include <stdio.h>
#include <string.h>

int find_char(char[], char[]);

int main()
{
    char str1[] = "Hellow", str2[] = "wje";
    int index = find_char(str1, str2);
    if (index == -1)
    {
        printf("The two strings doesn't contain any common characters\n");
    }
    else
    {
        printf("Found '%c' in '%s' at %d\n", str1[index], str1, index);
    }
    return 0;
}

int find_char(char str1[], char str2[])
{

    for (int i = 0; i < strlen(str2); i++)
    {
        for (int j = 0; j < strlen(str1); j++)
        {
            if (str1[j] == str2[i])
            {
                return j;
            }
        }
    }
    return -1;
}