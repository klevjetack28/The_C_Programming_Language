#include <stdio.h>

int main()
{
    int c, pc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c != pc)
        {
            putchar(c);
        }
        pc = c;
    }
    return 0;
}
