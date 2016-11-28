#include <stdio.h>
#include <semaphore.h>
#include <omp.h>

#define N 30

int main()
{
    int A[N][N], B[N][N], C[N][N], X[N][N], Y[N][N], Z[N][N];
    int i, j;
    sem_t sem1, sem2;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 2;
            B[i][j] = 3;
            C[i][j] = 2;
        }
    }

    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);

    omp_set_num_threads(4);
    #pragma omp parallel shared(sem1, sem2, A, B, C, X, Y, Z) private(i, j)
    {
        printf("Thread nº %d\n", omp_get_thread_num());

        #pragma omp sections
        {

            #pragma omp section
            {
                printf("before wait z \t");
                sem_wait(&sem1);
                sem_wait(&sem2);
                printf("before wait z \t");
                for (i = 0; i < N; i++) {
                    printf("wait z \t");
                    sem_wait(&sem1);
                    sem_wait(&sem2);
                    printf("Thread nº %d\n", omp_get_thread_num());
                    for (j = 0; j < N; j++)
                        Z[i][j] = X[i][j] + Y[i][j];
                    sem_post(&sem1);
                    sem_post(&sem2);
                }
            }

            #pragma omp section
            {
                sem_post(&sem1);
                for (i = 0; i < N; i++) {
                    printf("wait x \t");
                    sem_wait(&sem1);
                    printf("Thread nº %d\n", omp_get_thread_num());
                    for (j = 0; j < N; j++)
                        X[i][j] = A[i][j] * B[i][j];
                    sem_post(&sem1);
                }
                sem_post(&sem1);
            }

            #pragma omp section
            {
                sem_post(&sem2);
                for (i = 0; i < N; i++) {
                    printf("wait y \t");
                    sem_wait(&sem2);
                    printf("Thread nº %d\n", omp_get_thread_num());
                    for (j = 0; j < N; j++)
                        Y[i][j] = C[i][j] * -1;
                    sem_post(&sem2);
                }
                sem_post(&sem2);
            }
        }
    }

    printf("\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%4d", Z[i][j]);
        printf("\n");
    }
    printf("\n");

    return 0;
}
