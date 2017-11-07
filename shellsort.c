#include <stdio.h>

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap = gap / 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j = j - gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

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
    int v[10];
    int i;

    seed(9);

    for (i = 0; i < 10; ++i)
    {
        v[i] = rand();
    }

    for (i = 0; i < 10; ++i)
    {
        printf("%d,", v[i]);
    }

    printf("\n");
    
    shellsort(v, 10);

    for (i = 0; i < 10; ++i)
    {
        printf("%d,", v[i]);
    }

    printf("\n");
    
}