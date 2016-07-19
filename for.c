#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
 
int main(int argc, char *argv[]) {
  size_t i;
  int N = 10;
#pragma omp parallel for if(N > 5)
  for(i = 0; i < 10; ++i) {
    sleep (1);
    printf("hello world: %lu\n", i);
  }

#pragma omp parallel for if (omp_get_max_threads() > 3)
  for(i = 0; i < 10; ++i) {
    sleep (1);
    printf("hello world: %lu\n", i);
  }
  exit(EXIT_SUCCESS);
}
