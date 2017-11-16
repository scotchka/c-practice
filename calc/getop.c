#include <stdio.h>
#include <ctype.h>
#include "calc.h"



int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';                 // s[0] = c is first non-WS
  if (!isdigit(c) && c != '.') // c is operator
    return c;                  // e.g. s = ['+', '\0']
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0'; // e.g. s = ['1', '.', '2', '\0']
  if (c != EOF)
    ungetch(c); // c is operator
  return NUMBER;
}