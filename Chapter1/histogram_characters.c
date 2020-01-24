#include<stdio.h>

void main() {
    int c, i, j;
    int characters[80];

    for (i = 0; i < 80; i++) {
        characters[i] = 0;
    }
    
    while ((c = getchar()) != 'C') {
        if (c == ' ' || c == '\t' || c == '\n') {
            ;
        } else {
            characters[c - '0']++;
        }
    }

    for (i = 0; i < 80; i++) {
        printf("%c : ", (i + '0'));
        for (j = 0; j < characters[i]; j++) {
            printf("x");
        }
        printf("\n");
    }
}