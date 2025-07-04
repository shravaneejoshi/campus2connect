#include <stdio.h>

int main()
{
    int a, *p, *q;

    p = &a;
    q = p + 1;

    printf("%d\n", (int)q - (int)p);
}