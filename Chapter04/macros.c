#include <stdio.h>

#define swap(t, x, y) { t _z; \
                        _z = x; \
                        x = y;  \
                        y = _z; }

int main()
{
    int x = 10;
    int y = 5;
    
    printf("%d\n", x);
    printf("%d\n", y);

    swap(int, x, y);

    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}
