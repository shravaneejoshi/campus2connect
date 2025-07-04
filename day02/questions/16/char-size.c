#include <stdio.h>

int main()
{
    char* c;
    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(*c));
}