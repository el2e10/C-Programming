#include <stdio.h>

int main()
{
    int result = getchar() != EOF;
    printf("The value of the expression is %d", result);
    return 0;
}