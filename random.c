#include <stdio.h>

unsigned long next = 1;

int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void seed(unsigned int seed)
{
    next = seed;
}

int main(void)
{
    int i;

    seed(9);

    for (i = 0; i < 100; ++i)
    {
        printf("%d, ", rand());
    }
}
