#include <stdio.h>

int main(void)
{
    int c, i;
    char stack[1000];
    int len = 0;
    char open[] = "([{";
    char close[] = ")]}";

    while ((c = getchar()) != EOF)
    {
        for (i = 0; i < 3; ++i)
        {
            if (c == open[i])
            {
                stack[len] = c;
                ++len;
            }
            if (c == close[i])
            {
                if (len > 0 && stack[len - 1] == open[i])
                {
                    --len;
                }
                else
                {
                    printf("invalid");
                    return 0;
                }
            }
        }
    }
    if (len == 0)
    {
        printf("valid");
        return 0;
    }
    else
    {
        printf("invalid");
        return 0;
    }
}
