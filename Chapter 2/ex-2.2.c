#include <stdio.h>

#define MAX_LENGTH 100

int main()
{

    char sentence[MAX_LENGTH], c;

    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        if (c != '\n')
        {
            if (i < MAX_LENGTH)
            {

                sentence[i] = c;
            }
        }
    }
    printf("The sentence is %s\n", sentence);

    return 0;
}