#include <stdio.h>

int main()
{
    int x = 0; // 1
    int y = 0;
    int z = 1;

    x++ || y++ && z++;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
}

/**
 * precedence: && -> ||
 * short circuit gates behavior
 */