#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
  int i = 0;
#pragma omp parallel
  {
#pragma omp atomic
    i++;
    printf("i=%d\n", i);
  }
  return 0;
}
