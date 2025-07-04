#include <stdio.h>

int main()
{
    int x = 4 * 1024;
    x = x * 1024 * 1024;

    if (x > 0)
        printf("True\n");
    else
        printf("False\n");
}