#include <stdio.h>

int atoi(char s[]){
    int i;
    int n = 0;
    for (i=0; s[i] != '\0'; ++i) {
        // putchar(s[i]);
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

int main(void){
    printf("%d\n", atoi("94611"));
}