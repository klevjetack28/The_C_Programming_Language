#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
int strindex(char str[], char pat[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int found;
    
    while (my_getline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }

    return found;
}

int my_getline(char line[], int maxline)
{
    int c, i;

    i = 0;
    while (--maxline > 0 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

int strindex(char str[], char pat[])
{
    int i, j, k;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = i, k = 0; (str[j] != '\0') && (pat[k] != '\0') && (str[j] == pat[k]); j++, k++)
        {
        }
        if (k > 0 && pat[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}
