#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define M 10000
#define N 50.0
#define A 0.004
#define dt 0.25

int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	MPI_Request request1;
	int size, rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	FILE *fp;
  	if ((fp = fopen("results_2.txt", "w")) == NULL) {
		printf("FILE_ERROR\n");
    		return 0;
	}
	double U0[M], U[M], buf;
	for(int i = 0; i < M; i++) {
		if((-100 + i * ((200.0)/M) >= -1) && (-100 + i * ((200.0)/M) <= 1)) {
			U0[i] = 1;
		}
		else {
			U0[i] = 0;
		}
	}
	double h = 200.0 / M;
	for(int n = 0; n < N; n++) {

		if(rank == 0) {
			for(int m = 0; m * size < M; m++) {
                        	if(m * size == 0 || m * size == M - 1) {
                                	U[m * size] = 0;
                        	}
                        	else {
                                	U[m * size] = ((A*A) * dt/(h*h)) * (U0[m * size+1] - 2 * U0[m * size] + U0[m * size-1]) + U0[m * size];
                        	}
				for(int i = 1; i < size; i++) {
					MPI_Irecv(&buf, 1, MPI_DOUBLE, i, 228, MPI_COMM_WORLD, &request1);
                                	MPI_Wait(&request1, MPI_STATUS_IGNORE);
					U[i + m *size] = buf;
				}
               		}
			memcpy(U0, U, M * sizeof(double));
			MPI_Bcast(U0, M, MPI_DOUBLE, 0, MPI_COMM_WORLD);
		}
		else {
			for(int m = 0; m < M / size; m++) {
                                if(rank + m * size == 0 || rank + m * size == M - 1) {
					buf = 0;
                                }
                                else {
                                        buf = ((A*A) * dt/(h*h)) * (U0[rank + m * size+1] - 2 * U0[rank + m * size] + U0[rank + m * size-1]) + U0[rank + m * size];
                                }
				MPI_Isend(&buf, 1, MPI_DOUBLE, 0, 228, MPI_COMM_WORLD, &request1);
				MPI_Wait(&request1, MPI_STATUS_IGNORE);
			}
			MPI_Bcast(U0, M, MPI_DOUBLE, 0, MPI_COMM_WORLD);
		}
	}
	for(int i = 0; i < M; i++) {
		fprintf(fp, "%lf\t%lf\n", i*h, U[i]);
        }
	fclose(fp);
	MPI_Finalize();
	return 0;
}
