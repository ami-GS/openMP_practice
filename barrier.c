#include <omp.h>
#include <stdio.h>

int main() {
  int id, ans = 0;
  omp_set_num_threads(3);
  int a[3];
#pragma omp parallel private(id) 
  { 
    id = omp_get_thread_num(); 
    printf("id %d\n", id);
    a[id] = id*10;
    int i;
#pragma barrier  //wait threads
#pragma for private(i)
    for(i=0;i<3;i++) {
      ans += a[i];
      printf("ans %d\n", ans);
    }
  }

  printf("ans = %d\n", ans);
  return 0;
}
