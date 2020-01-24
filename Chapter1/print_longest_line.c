#include<stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[], int maxline);
void copy (char to[], char from[]);

/* print the longest input line */
void main() {
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)  { /* there was a line */
        printf("Length of the longest line: %d\n", max);
        printf("%s\n", longest);
    }
}

/* read a line into s, return length */
int getLine(char s[], int lim) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (j < lim - 2) {
            s[j] = c;
            j++;
        }
    }
    if(c == '\n') {
        s[j] = c;
        j++;
        i++;
    }
    s[j] = '\0';
    return i;
}

/* copy 'from' into 'to' */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}