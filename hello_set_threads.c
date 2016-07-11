#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
  omp_set_num_threads(12);
#pragma omp parallel
  {
    printf("hello world\n");
  }
  exit(EXIT_SUCCESS);
}
