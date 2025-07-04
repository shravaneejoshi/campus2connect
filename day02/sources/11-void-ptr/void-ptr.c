#include <stdio.h>

int main() {
  int i = 10;

  void *pi = &i;

  printf("pi: %p, &i: %p\n", pi, &i);
  printf("*pi: %d\n", *pi);

  return 0;
}
