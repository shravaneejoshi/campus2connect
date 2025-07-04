#include <stdio.h>

int main()
{
    int a = 3;
    int b = ++a + a++ + --a;
    printf("Value of b is %d\n", b);
}