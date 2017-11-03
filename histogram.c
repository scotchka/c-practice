#include <stdio.h>

int main() {

    int count[26];
    int c, i, j;

    for (i = 0; i < 26; ++i)
        count[i] = 0;

    while ((c = getchar()) != EOF){
        ++count[c - 'a'];
    }

    for (i = 0; i < 26; ++i) {
        putchar(i+'a');
        for (j = 0; j < count[i]; ++j)
            putchar('*');
        putchar('\n');
    }
}