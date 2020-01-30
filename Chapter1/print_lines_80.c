#include<stdio.h>
#define MAXLINE 1000 /* maximum input length */

int getLine(char line[], int maxline);

/* print input lines linger than 80 */
void main() {
    int length;         /* length of current line */
    int min;            /* minimum length to be printed */
    char line[MAXLINE];  /* current input line */

    min = 80;
    while((length = getLine(line, MAXLINE)) > 0) {
        if (length > min) {
            printf("%s\n", line);
        }
    }
} 

/* read a line into array and return length */
int getLine(char line[], int lim) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (j < lim -2) {
            line[j] = c;
            j++;
        }
    }

    if (c == '\n') {
        line[j] = c;
        j++;
        i++;
    }

    line[j] = '\0';
    return i;
}