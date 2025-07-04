#include <stdio.h>

void function_1(int a) {
  printf("function_1(): a = %d\n", a);
}

void function_2(int b) {
  printf("function_2(): b = %d\n", b);
}

int main() {
    void (*pf)(int);
    pf = function_1;
    pf(10);

    void (*qf)(int);
    qf = &function_2;
    qf(20);

    return 0;
}
