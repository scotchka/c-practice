#include <stdio.h>
#define MAXVAL 100

static int pos = 0;
static double stack[MAXVAL];

void push(double num) {
  if (pos >= MAXVAL) {
    printf("stack full");
    return;
  }

  stack[pos++] = num;
}

double pop(void) {
  if (pos <= 0) {
    printf("stack empty");
    return 0.0;
  }
  return stack[--pos];
}