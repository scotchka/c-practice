#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *[], int);
void writelines(char *[], int);

void qsort(void *[], int, int, int (*comp)(void *, void *));
int numcmp(const char *, const char *);

int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **)lineptr, 0, nlines - 1,
          (int (*)(void *, void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big\n");
    return 1;
  }
}

#define MAXLEN 1000

int get_line(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}
