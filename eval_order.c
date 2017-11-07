#include <stdio.h>

int a(void) {
    printf("a ");
    return 1;
}

int b(void) {
    printf("b ");
    return 1;
}

int c(void) {
    printf("c ");
    return 1;
}

int main(void) {

    int n;
    n = a() + b() + (a() + b());
    printf("%d\n", n);
    return 0;
}