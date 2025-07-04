#include <stdio.h>

int main()
{
    struct {
        int f1:3;
        unsigned int f2:1;
    } x = {5, 1};

    printf("%d, %d\n", x.f1, x.f2);
    printf("%ld\n", sizeof(x));
}