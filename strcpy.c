#include <stdio.h>

void _strcpy(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}

int main(void) {
  char t[] = "hello world!";
  char s[100];

  _strcpy(s, t);

  printf("%s\n%s\n", s, t);

//   printf("%d %d\n", s, t);
}