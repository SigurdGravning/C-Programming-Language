#include <stdio.h>

void main() {
    int c, nl, t, b;

    nl = 0;
    t = 0;
    b = 0;

    while ((c = getchar()) != 'C') {
        if (c == '\n') {
            nl++;
        } else if (c == '\t') {
            t++;
        } else if (c == ' ') {
            b++;
        }
    }
    printf("Newlines: %d\n", nl);
    printf("Tabs: %d\n", t);
    printf("Blanks: %d\n", b);
}