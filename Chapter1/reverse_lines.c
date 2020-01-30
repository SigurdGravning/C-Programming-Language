#include<stdio.h>
#define MAXLINE 1000    /* maximum length input line */

int getLine(char line[], int maxline);
void reverse(char line[], int length);

void main() {
    int length;     /* length of current input line */
    char line[MAXLINE];    /* current input line */

    while ((length = getLine(line, MAXLINE)) > 0) {
        reverse(line, length);
        printf("%s", line);
    }
    printf("\n");
}

int getLine(char line[], int limit) {
    int c, i, j;

    j = 0;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (j < limit - 2) {
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

void reverse(char line[], int length) {
    int i, j;
    char temp[length];

    j = length;
    for (i = 0; i < length; i++) {
        j--;
        temp[i] = line[j];
    }

    for (i = 0; i < length; i++) {
        line[i] = temp[i];
    }
}