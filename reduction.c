#include <stdio.h>
#include <omp.h>

int main() {
  
  int sum = 0, N = 10;
  int i;
#pragma omp parallel for reduction(+:sum)
    for(i=0; i<N; i++) {
      sum++;
    }
    printf("%d\n", sum);
    return 0;
}
