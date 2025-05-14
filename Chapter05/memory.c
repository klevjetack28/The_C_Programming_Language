#include <stdio.h>
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char* alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    return 0;
}

void afree(char* p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    {
        allocp = p;
    }
}

int main()
{
    int len = 8;
    char* str = alloc(len);
    for(int i = 0; i < len - 1; i++)
    {
        str[i] = 'a';
    }
    str[len - 1] = '\0';
    printf("%s\n", str);

    return 0;
}
