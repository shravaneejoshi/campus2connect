#include <stdio.h>

int main()
{
    char c1 = 'a', c2 = 'b', c;
    c = c1 + c2;

    if (c > 'c')
        printf("True\n");
    else
        printf("False\n");
}