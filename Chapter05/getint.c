#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int main()
{

}

int getline(int *pn)
{
    int c, sign;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c = '-')
    {
        c = getch();
    }
    for (*pn = 0; isdigit(c), c = getc())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
