#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int convert_str_to_hex(char[]);

int main()
{
    int result = convert_str_to_hex("1ABDEF");
    if (result == -1)
    {
        printf("The hex code provided is not valid\n");
    }
    else
    {
        printf("The decimal value is %d\n", result);
    }
    return 0;
}

int convert_str_to_hex(char str[])
{

    int result = 0, tmp;
    int len = strlen(str) - 1;
    for (int i = 0; i <= len; i++)
    {
        char c = tolower(str[i]);
        if (c >= '0' && c <= '9')
        {
            tmp = c - 48;
            result += tmp * pow(16, len - i);
        }
        else if (c >= 'a' && c <= 'f')
        {
            tmp = (c - 97 + 10);
            result += tmp * pow(16, len - i);
        }
        else
        {
            return -1;
        }
    }
    return result;
}