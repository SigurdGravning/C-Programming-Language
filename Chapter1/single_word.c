#include <stdio.h>
#define IN  1  /* inside a word */
#define OUT 0  /* outside a word */ 

void main() {
    int c, state;
    state = OUT;
    while ((c = getchar()) != 'C') {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                printf("\n");
            }
            state = OUT;
        } else {
            state = IN;
            putchar(c);
        }
    } 
}