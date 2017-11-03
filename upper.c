#include <stdio.h>

int upper(int c) {
    return c - 'a' + 'A';
}

int main(){
    float c;
    c = (float)42;
    printf("%f\n", c);
}