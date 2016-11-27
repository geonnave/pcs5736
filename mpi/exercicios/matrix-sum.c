#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int X[N][N], Y[N][N], Z[N][N], W[N][N];
int collector_rank = 3;

void tarefa1() {
    int i, j, rank, matrix_size, buf_size;
    int *buf;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello from rank %d\n", rank);

    MPI_Pack_size(N*N, MPI_INT, MPI_COMM_WORLD, &matrix_size);
    buf_size = matrix_size + N*MPI_BSEND_OVERHEAD;
    buf = (int *) malloc(buf_size);
    MPI_Buffer_attach(buf, buf_size);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            X[i][j] = i;
        }
        MPI_Bsend(X[i], N, MPI_INT, collector_rank, i, MPI_COMM_WORLD);
    }
    MPI_Buffer_detach(&buf, &buf_size);
}
void tarefa2() {
    int i, j, rank, matrix_size, buf_size;
    int *buf;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello from rank %d\n", rank);

    MPI_Pack_size(N*N, MPI_INT, MPI_COMM_WORLD, &matrix_size);
    buf_size = matrix_size + N*MPI_BSEND_OVERHEAD;
    buf = (int *) malloc(buf_size);
    MPI_Buffer_attach(buf, buf_size);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Y[i][j] = 1;
        }
        MPI_Bsend(Y[i], N, MPI_INT, collector_rank, i, MPI_COMM_WORLD);
    }
    MPI_Buffer_detach(&buf, &buf_size);
}
void tarefa3() {
    int i, j, rank, matrix_size, buf_size;
    int *buf;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello from rank %d\n", rank);

    MPI_Pack_size(N*N, MPI_INT, MPI_COMM_WORLD, &matrix_size);
    buf_size = matrix_size + N*MPI_BSEND_OVERHEAD;
    buf = (int *) malloc(buf_size);
    MPI_Buffer_attach(buf, buf_size);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Z[i][j] = 0;
        }
        MPI_Bsend(Z[i], N, MPI_INT, collector_rank, i, MPI_COMM_WORLD);
    }
    MPI_Buffer_detach(&buf, &buf_size);
}

void tarefa4() {
    int i, j, rank;
    int x[N], y[N], z[N];
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hello from rank %d\n", rank);
    for (i = 0; i < N; i++) {
        MPI_Recv(x, N, MPI_INT, 0, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(y, N, MPI_INT, 1, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(z, N, MPI_INT, 2, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        for (j = 0; j < N; j++) {
            W[i][j] = x[j] + y[j] + z[j];
            printf("%3d", W[i][j]);
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
