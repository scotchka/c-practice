#include <stdio.h>

int main(){

    int a[5], i;

    for (i=0; i<5; i++){
        a[i]= 0;
    }


    i=2;
    a[i] = ++i;

    for (i=0; i<5; i++){
        printf("%d", a[i]);
    }

}