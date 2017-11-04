#include <stdio.h>

int any(char[], char[]);

int main()
{
    printf("%d\n", any("hello", "h"));
}

int any(char s1[], char s2[])
{
    int i, j;

    i = 0;
    while (s1[i++] != '\0')
    {
        j = 0;
        while (s2[j] != '\0')
        {
            if (s1[i - 1] == s2[j++])
                return i - 1;
        }
    }
    return -1;
}
