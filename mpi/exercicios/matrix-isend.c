#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int collector_rank = 3;

void tarefa1() {
    int i, j, rank;
    int A[N][N], B[N][N], X[N][N];
    MPI_Request req;
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello from rank %d\n", rank);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
            X[i][j] = A[i][j] * B[i][j];
        }
        MPI_Isend(X[i], N, MPI_INT, collector_rank, i, MPI_COMM_WORLD, &req);
        MPI_Wait(&req, &status);
    }
}
void tarefa2() {
    int i, j, rank;
    int C[N][N], D[N][N], Y[N][N];
    MPI_Request req;
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello from rank %d\n", rank);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 2;
            D[i][j] = 2;
            Y[i][j] = C[i][j] * D[i][j];
        }
        MPI_Isend(Y[i], N, MPI_INT, collector_rank, i, MPI_COMM_WORLD, &req);
    }
    MPI_Wait(&req, &status);
}
void tarefa3() {
    int i, j, rank;
    int E[N][N], F[N][N], Z[N][N];
    MPI_Request req;
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello from rank %d\n", rank);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            E[i][j] = 3;
            F[i][j] = 3;
            Z[i][j] = E[i][j] * F[i][j];
        }
        MPI_Isend(Z[i], N, MPI_INT, collector_rank, i, MPI_COMM_WORLD, &req);
        MPI_Wait(&req, &status);
    }
}

void tarefa4() {
    int i, j, rank;
    int x[N], y[N], z[N];
    int T[N][N], W[N][N];
    MPI_Request reqx, reqy, reqz;
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello from rank %d\n", rank);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            T[i][j] = 2;

    for (i = 0; i < N; i++) {
        MPI_Irecv(x, N, MPI_INT, 0, i, MPI_COMM_WORLD, &reqx);
        MPI_Irecv(y, N, MPI_INT, 1, i, MPI_COMM_WORLD, &reqy);
        MPI_Irecv(z, N, MPI_INT, 2, i, MPI_COMM_WORLD, &reqz);
        MPI_Wait(&reqx, &status);
        MPI_Wait(&reqy, &status);
        MPI_Wait(&reqz, &status);
        for (j = 0; j < N; j++) {
            W[i][j] = (x[j] + y[j] + z[j]) * T[i][j];
            printf("%4d", W[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int rank, world_size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    switch(rank) {
    case 0:
        tarefa1();
        break;
    case 1:
        tarefa2();
        break;
    case 2:
        tarefa3();
        break;
    case 3:
        tarefa4();
        break;
    }

    MPI_Finalize();
}
