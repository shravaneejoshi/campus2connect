#include <stdio.h>

int main() {
  int *p = NULL;
  printf("%p, 0x%llu\n", NULL, (long long unsigned int)NULL);
  printf("%d\n", *p);
}
