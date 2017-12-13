#define BUFSIZ 1024

int read(int, char *, int);
int write(int, char *, int);

int main(void) {
  char buf[BUFSIZ];
  int n;

  while ((n = read(0, buf, BUFSIZ)) > 0)
    write(1, buf, n);

  return 0;
}