#include <ctype.h>
#include <stdio.h>
#define SIZE 5

int getch(void);
void ungetch(int);

int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-')
    c = getch();

  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');

  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}

int main(void) {
  int n, array[SIZE], getint(int *);
  for (n = 0; n < SIZE && getint(&array[n]) != EOF; ++n)
    ;
  for (n = 0; n < SIZE; ++n)
    printf("%d\n", array[n]);
}