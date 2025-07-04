#include <stdio.h>

int main()
{
    int x = 1, y = 1;

    if ( x++ >= 0 || ++y >= 0 ) { // try with &&
        printf("%d\n", x);
        printf("%d\n", y);
    }

}

/*
short circuit rule for conditional expression for logic gates
*/