#include <mpi.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	MPI_Request request1;
//	printf("Hello world\n");
	int size, rank;
	double result = 0, N = 1000000000, buf_recv;
	double buf;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0) {
		for(int i = 0; i < N/size; i++) {
                        result = result + (4/N)*sqrt(1-((rank+i*size)/N)*((rank+i*size)/N));
                }
		for(int i = 1; i < size; i++) {
			MPI_Irecv(&buf, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 228, MPI_COMM_WORLD, &request1);
			MPI_Wait(&request1, MPI_STATUS_IGNORE);
			result = result + buf;
		}
		printf("PI = %lf\n", result);

	}
	else {
		for(int i = 0; i < N/size; i++) {
               		result = result + (4/N)*sqrt(1-((rank+i*size)/N)*((rank+i*size)/N));
                }
                buf = result;
		MPI_Isend(&buf, 1, MPI_DOUBLE, 0, 228, MPI_COMM_WORLD, &request1);
		MPI_Wait(&request1, MPI_STATUS_IGNORE);
	}
	MPI_Finalize();
	return 0;
}
