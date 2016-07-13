#include <stdio.h>
#include <omp.h>
#include <unistd.h>

main(int argc, char *argv[]) {

  int nthreads, threadID;

#pragma omp parallel private(threadID)
  {
    threadID = omp_get_thread_num();
    usleep(10000);
    printf("this is thread ID = %d\n", threadID);

    if (threadID == 0) 
      {
	nthreads = omp_get_num_threads();
	printf("Number of threads = %d\n", nthreads);
      }
  }

  printf("\n\n");
  int t_ID;
#pragma omp parallel
  {
    t_ID = omp_get_thread_num();
    usleep(10000);
    printf("this is thread ID = %d\n", t_ID);

    if (t_ID == 0) 
      {
	nthreads = omp_get_num_threads();
	printf("Number of threads = %d\n", nthreads);
      }
  }
}
