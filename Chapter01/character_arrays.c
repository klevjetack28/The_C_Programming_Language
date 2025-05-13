#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) != 0)
    {
        if (len > max)
        {
            copy(longest, line);
            max = len;
        }
    }
    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}

int my_getline(char line[], int maxline)
{
    int c, i;

    for (i = 0; (i < maxline - 1) && ((c = getchar()) != EOF && c != '\n'); i++)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++c;
    }
    line[i] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

