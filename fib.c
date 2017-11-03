#include <stdio.h>

#define UPPER 50

long fib(int);

long cache[UPPER];

int main(void) {
    int n;

    for (n=0; n < UPPER; ++n)
        cache[n] = -1;    
    for (n=0; n < UPPER; ++n)
        printf("%d\t%ld\n", n, fib(n));
}

long fib(int n) {

    if (cache[n] != -1)
        return cache[n];

    if (n < 2)
        return 1;
    
    cache[n] = fib(n-2) + fib(n-1);
    return cache[n];
}