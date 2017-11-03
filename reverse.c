#include <stdio.h>
#define MAXLINE 1000

void reverse(char original[], char reversed[]);
int get_line(char line[], int maxline);

int main() {

    char line[MAXLINE];
    char reversed[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        reverse(line, reversed);

        printf("%s\n", reversed);
    }

}

void reverse(char original[], char reversed[])
{
    int i, len;
    for (len=0; original[len]!= '\0'; ++len);
    
    for (i=0; i < len; ++i)
        reversed[i] = original[len-1-i];
    reversed[i] = '\0'; 
}

int get_line(char s[], int lim)
{
    // printf("%d %s", lim, s);
    // print_array(s);
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    // printf("%s", s);
    // print_array(s);
    // printf("%d", i);
    return i;
}