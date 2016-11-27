#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
    // Find out rank, size
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int e_per_proc = N / world_size;
    int a[N] = { 0 };
    int partial_a[e_per_proc], partial_res[e_per_proc];
    int i, result;


    if (world_rank == 0)
        for (i = 0; i < N; i++)
            a[i] = i;
    if (world_rank == 0)
        for (i = 0; i < N; i++)
            printf("%3d", a[i]);

    MPI_Scatter(a, e_per_proc, MPI_INT, partial_a, e_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Reduce(partial_a, partial_res, e_per_proc, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        result = partial_res[0];
        for (i = 1; i < e_per_proc; i++)
            if (partial_res[i] > result)
                result = partial_res[i];

        printf("\nMAX is %d\n", result);
    }

    MPI_Finalize();
}
