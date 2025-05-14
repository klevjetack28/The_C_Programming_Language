#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int c;
    int (*func)(int) = ((argv[0][2] == 'u') ? toupper : tolower);
    
    while (c = getchar())
    {
        putchar(func(c));
    }
    return 0;
}
