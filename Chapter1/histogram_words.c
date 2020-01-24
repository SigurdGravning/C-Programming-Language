#include<stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

void main() {
    int c;
    int i = 0;
    int j = 0;
    int lengthOfWords[10];
    int state = IN;

    for (i = 0; i < 10; i++){
        lengthOfWords[i] = 0;
    }

    i = 0;
    printf("Type in up to ten words:\n");
    while ((c = getchar()) != 'C') {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            i++;
            lengthOfWords[i]++;
        } else {
            lengthOfWords[i]++;
        }
    }

    printf("Length of words:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < lengthOfWords[i]; j++) {
            printf("x");
        } 
        printf("\n");
    }
}