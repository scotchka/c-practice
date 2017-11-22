#include <stdio.h>

int main(int argc, char *argv[]) {
  ++argv;
  while (*(argv + 1)) {
    printf("%s ", *argv);
    ++argv;
  }
  printf("%s\n", *argv);
}
