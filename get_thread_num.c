#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
  int i;
  int THREAD_NUM = 64;
#pragma omp parallel for
  for (i = 0; i < THREAD_NUM; i++) {
    printf("%d: %d\n", omp_get_thread_num(), i);
  }
}
