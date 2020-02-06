#include<stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int length;     /* length of the current input line */
int getLine(char line[], int maxline);
void detab(char line[], int tabstop);
void shift(char line[], int position);

void main() {
    extern int length;
    int tabstop;
    char line[MAXLINE];     /* current input line */

    tabstop = 7;
    while((length = getLine(line, MAXLINE)) > 0) {
        detab(line, tabstop);

        printf("%s\n", line);
    }
}

/* read the line into an array, return the length */
int getLine(char line[], int limit) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
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

/* replace tabs in the given line with spaces to the next tabstop */
void detab(char line[], int tabstop) {
    int i;

    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\t') {
            line[i] = ' ';
            while ((i + 2) % tabstop != 0) {
                shift(line, i);
                i++;
                line[i] = ' ';
            }
        }
    }
}

/* shift the content of the array one step to the right, starting from the given position */
void shift(char line[], int position) {
    extern int length;
    int i;

    for (i = length - 2; i > position + 1; i--) {
        line[i] = line[i - 1];
    }
}