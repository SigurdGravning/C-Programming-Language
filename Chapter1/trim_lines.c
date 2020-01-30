#include<stdio.h>
#define MAXLINE 1000 /* maximum length input line */

int getLine(char line[], int maxline);
void trim(char line[], int length);
_Bool isWhiteSpace(char c);

void main() {
    int length;     /* length of current input line */
    char line[MAXLINE];

    while ((length = getLine(line, MAXLINE)) > 0) {
        /* if a line has the length of one, it is empty */
        if (length > 1) {
            trim(line, length);
            printf("%s\n", line);
        }
    }
}

/* read line into s, return length of line */
int getLine(char s[], int limit) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (j < limit - 2) {
            s[j] = c;
            j++;
        }
    }
    if (c == '\n') {
        s[j] = c;
        j++;
        i++;
    }

    s[j] = '\0';
    return i;
}

/* trim whitespace of the end of line */
void trim(char s[], int length) {
    while (length > 2 && isWhiteSpace(s[length - 2])) {
        length--;
    }

    if (isWhiteSpace(s[length - 1])) {
        length--;
    }

    if (isWhiteSpace(s[length])) {
        s[length] = '\0';
    }
}

/* check if character is whitespace */ 
_Bool isWhiteSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}