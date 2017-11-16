#include <ctype.h>
#include <stdio.h>



int main(void) {
  int c, i;
  char string[] = "-.405";
  double atof(char s[]);

  printf("%s\n", string);
  printf("%f\n", atof(string));
}

double atof(char s[]) {
  int c, i, sign = 1;
  int denom = 1, power = 1;
  double result = 0.0;

  for (i = 0; (c = s[i]) != '\0'; i++) {
    if (isdigit(c)) {
      result = result * 10 + (c - '0');
      power = power * denom;
    }
    if (c == '-')
      sign = -1;

    if (c == '.')
      denom = 10;
  }
//   printf("denom=%d\n", denom);
  return sign * result / power;
}