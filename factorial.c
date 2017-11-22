#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int n = atoi(argv[1]);
  int acc = atoi(argv[2]);
  if (n == 1) {
    printf("%d\n", acc);
    return 1;
  } else {
    acc = n * acc;
    --n;
    sprintf(argv[1], "%d", n);
    sprintf(argv[2], "%d", acc);
    return main(argc, argv);
  }
}