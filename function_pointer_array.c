#include <stdio.h>

int inc(int n) { return n + 1; }

int twice(int n) { return n * 2; }

int main(void) {

  int (*f[])(int) = {inc, twice};

  int n;
  for (n = 0; n < 2; ++n)
    printf("%d\n", (*f[n])(42));
}