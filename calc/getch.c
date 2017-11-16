#include <stdio.h>
#define BUFSIZE 100

static char buffer[BUFSIZE];
static int buf_pos = 0;

int getch(void) { return (buf_pos > 0) ? buffer[--buf_pos] : getchar(); }

void ungetch(int c) {
  if (buf_pos >= BUFSIZE)
    printf("exceed buffer limit\n");
  else
    buffer[buf_pos++] = c;
}