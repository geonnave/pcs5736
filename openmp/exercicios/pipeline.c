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

int return_1() {
    return 1;
}

int main()
{
    int A[N][N], B[N][N], C[N][N], X[N][N], Y[N][N], Z[N][N];
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 2;
            B[i][j] = 3;
            C[i][j] = 2;
        }
    }


    #pragma omp parallel num_threads(2) shared(A, B, C, X, Y, Z) private(i, j)
    {
        printf("Thread nº %d\n", omp_get_thread_num());

        #pragma omp sections
        {
            #pragma omp section
            {
                for (i = 0; i < N; i++) {
                    for (j = 0; j < N; j++) {
                        X[i][j] = A[i][j] * B[i][j];
                    }
                }
            }

            #pragma omp section
            {
                for (i = 0; i < N; i++) {
                    for (j = 0; j < N; j++) {
                        Y[i][j] = C[i][j] * -1;
                    }
                }
            }
        }

        #pragma omp barrier

        #pragma omp for
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++) {
                Z[i][j] = X[i][j] + Y[i][j];
            }
        }
    }

    printf("\n");
    printm(Z);

    return 0;
}
