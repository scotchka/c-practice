#include <stdio.h>

int main()
{

    int c, nl, ns, nt;

    nl = 0; // lines
    ns = 0; // spaces
    nt = 0; // tabs

    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++ns;
        else if (c == '\t')
            ++nt;

    printf("lines: %d\n", nl);
    printf("spaces: %d\n", ns);
    printf("tabs: %d\n", nt);
    
}