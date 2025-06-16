#include <stdio.h>
#include <ctype.h>

double atof(char str[]);

int main()
{
    char str[] = "-1.1113";
    printf("%s\n", str);
    double num = atof(str);
    printf("%f\n", num);
}

double atof(char str[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(str[i]); i++);
    sign = (str[i] == '-') ? -1 : 1;
    if (str[i] == '+' || str[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(str[i]); i++)
    {
        val = 10.0 * val + (str[i] - '0');
    }
    if (str[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(str[i]); i++)
    {
        val = 10.0 * val + (str[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}
