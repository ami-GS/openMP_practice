#include <omp.h>
#include <stdio.h>
 
int main(void) {
 
#pragma omp parallel sections num_threads(3)
  {
#pragma omp section
    printf("print0-1 %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
 
#pragma omp section
    printf("print0-2 %d of %d\n", omp_get_thread_num(), omp_get_num_threads());

#pragma omp section
    {
      printf("print1 %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
      printf("print2 %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
  }
  return 0;
}
