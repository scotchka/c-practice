#include <stdio.h>

int main()
{

    int c = getchar();

    while (c != EOF)
    {
        if (c != ' ')
        {
            putchar(c);
            c = getchar();
        }
        else
        {
            putchar(' ');

            while (c == ' ')
                c = getchar();
        }
    }
    // putchar(EOF);
}