#include <stdio.h>

int main()
{
    int a, b = 1, c = 1;
    a = sizeof(c = ++b + 1);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
}