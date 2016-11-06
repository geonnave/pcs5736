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
    int a[N][N];
    int i = 0, j = 0, acc = 0, pi = -1, pj = -1;
    int elem = 28;
    int found = 0;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = 28;

    printm(a);

    omp_set_num_threads(2);
#pragma omp parallel for private(i, j) shared(pi, pj, found)
    for (i = 0; i < N; i++)
    {
        if (found) continue;
        for (j = 0; j < N; j++) {
            if (a[i][j] == elem) {
                pi = i;
                pj = j;
                printf("Thread %d found %d at a[%d][%d]!\n", omp_get_thread_num(), elem, pi, pj);
                found = 1;
                break;
            }
        }
    }
    printf("\n");

    if (pi >= 0 && pj >= 0)
        printf("Found %d at a[%d][%d]\n", elem, pi, pj);
}
