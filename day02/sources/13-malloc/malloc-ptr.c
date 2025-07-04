#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = (int *)malloc(400);

  printf("before: %d\n", *p);
  *p = 4;
  printf("after: %d\n", *p);

  free(p);
  return 0;
}
