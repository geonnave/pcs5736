#include <stdio.h>
#include <omp.h>

#define N 10

int return_1() {
    return 1;
}

int main()
{
    int results[N];
    int (*tasks[N])();
    int current_task = 0;
    int i, j;

    for (i = 0; i < N; i++)
        tasks[i] = return_1;

#pragma omp parallel num_threads(2) shared(tasks, results, current_task)
    {
        int _current;
        printf("Thread nº %d\n", omp_get_thread_num());
        while (1) {
            if (current_task >= N) {
                printf("Tasks are over! Thread nº %d will stop.\n", omp_get_thread_num());
                break;
            }
            _current = current_task;

            #pragma omp atomic
            current_task++;

            results[_current] = (*tasks[_current])();
        }
    }

    printf("\n\n\n");
    for (i = 0; i < N; i++)
        printf("Result is %d\n", results[i]);

    return 0;
}
