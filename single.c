#include <stdio.h> 

  
int main(void) { 
  int singlec = 0, parallelc = 0;
  
#pragma omp parallel num_threads(3)
  { 
#pragma omp single
    { 
      printf("here single tread # %d\n", singlec++);
    } 

    printf("here parallel tread # %d\n", parallelc++);

#pragma omp single
    { 
      printf("here single tread # %d\n", singlec++);
    } 
  } 
  return 0; 
}
