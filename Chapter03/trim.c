#include <stdio.h>
#include <string.h>
int trim(char s[]);

int main()
{
    char str[] = "STRINGAHHHHHH                  \t\t\t\t\t\t\n\n\n\n";
    printf("%s\n", str);
    trim(str);
    printf("%s\n", str);
}

int trim(char s[])
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
    {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        {
            break;
        }
    }
    s[n + 1] = '\0';
    return n;
}   
