#include <stdio.h>
#include <omp.h>

int main() {
  int N = 1000;
  int i, j, k;

  int ans = 0;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
	ans++;
      }
    }
  }
  printf("ans=%d\n", ans);

  ans = 0;
#pragma omp parallel for collapse(3)
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
#pragma omp atomic
	ans++;
      }
    }
  }
  printf("ans=%d\n", ans);
}
