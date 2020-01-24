#include <stdio.h>

void main() {
    int c;
    // string output;

    while ((c = getchar()) != 'C') {
        if (c == ' ') {
            putchar(c);
            while (c == ' ') {
                c = getchar();
            }
        }
        putchar(c);        
    }
    printf("\n");
}