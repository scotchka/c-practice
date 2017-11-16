#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main(void) {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      push(pop() / op2);
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    }
  }
  return 0;
}

#define MAXVAL 100

int pos = 0;
double stack[MAXVAL];

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

#include <ctype.h>

int getch(void);
void ungetch(int);

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

#define BUFSIZE 100

char buffer[BUFSIZE];
int buf_pos = 0;

int getch(void) { return (buf_pos > 0) ? buffer[--buf_pos] : getchar(); }

void ungetch(int c){
    if (buf_pos >= BUFSIZE)
        printf("exceed buffer limit\n");
    else
        buffer[buf_pos++] = c;
}