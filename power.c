#include <stdio.h>

int power(int m, int n);

int main(void)
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

int power(int base, int n)
{
    int res;
    for (res = 1; n > 0; --n)
        res = res * base;
    return res;
}