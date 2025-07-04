#include <stdio.h>

int main()
{
    char c;
    printf("c = %x\n", c = -1);
    printf("c = %d\n", c = -1);
    printf("c = %d\n", c = 255);
}

/**
 * 
 * printf is a varidic function
 * 
 * rule: default argument promotion rule (char -> int)
 */