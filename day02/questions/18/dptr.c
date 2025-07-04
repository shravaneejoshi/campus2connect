#include <stdio.h>

int main()
{
    int a = 100, *p;

    p = &a;

    printf("%d\n", *&a);
    printf("%d\n", **&p);
}