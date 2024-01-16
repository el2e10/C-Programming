#include <stdio.h>
#include <string.h>

void squeeze(char[], char[]);
void remove_character(char[], int);

int main()
{
    char str_1[] = "sets the last six", str_2[] = "hellow";
    squeeze(str_1, str_2);
    printf("The result is %s\n", str_1);
    return 0;
}

void squeeze(char s1[], char s2[])
{

    for (int i = 0; i < strlen(s1); i++)
    {
        for (int j = 0; j < strlen(s2); j++)
        {
            if (s1[i] == s2[j])
            {
                remove_character(s1, i);
            }
        }
    }
}

void remove_character(char str[], int index)
{
    for (int i = index; i < strlen(str); i++)
    {
        str[i] = str[i + 1];
    }
}
