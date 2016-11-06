#include <stdio.h>
#include <omp.h>

#define N 10

void printm(int m[N][N]) {
  int i = 0, j = 0;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%4d", m[i][j]);
    printf("\n");
  }
  printf("\n");
}

int main()
{
  int a[N][N], b[N][N], res[N][N] = { 0 };
  int i = 0, j = 0;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      a[i][j] = b[i][j] = i + j;

  printm(a);
  printm(b);

  omp_set_num_threads(2);
  #pragma omp parallel for private(i, j) shared(res)
  for (i = 0; i < N; i++)
  {
    printf("Thread nº %d\n", omp_get_thread_num());
    for (j = 0; j < N; j++) {
      res[i][j] += a[i][j] + b[i][j];
    }
  }

  printm(res);
}
