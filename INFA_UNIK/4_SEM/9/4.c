#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
	int A[100], *a;
	for(int i=0; i < 100; i++) {
		A[i] = i;
	}
	MPI_Init(&argc, &argv);
	char* buf1 = "РАЗ РАЗ РАЗ\n";
	char* buf2 = "ЭТО ХАРДБАСС \n";
	char* buf3 = (char*)malloc(50*sizeof(char));
	MPI_Request request1, request2, request3;
//	printf("Hello world\n");
	int size, rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	double time;
	int i = 0;
//	printf("RANK = %d\nSIZE = %d\n", rank, size);
	if(rank == 0) {
		for(i = 0; i < 100; i++) {
                	A[i] = i;
		}	
			MPI_Isend(A, 100, MPI_INT, 1, 228, MPI_COMM_WORLD, &request1);
			MPI_Wait(&request1, MPI_STATUS_IGNORE);
			MPI_Isend(A, 100, MPI_INT, 2, 228, MPI_COMM_WORLD, &request1);
                        MPI_Wait(&request1, MPI_STATUS_IGNORE);
			MPI_Isend(A, 100, MPI_INT, 3, 228, MPI_COMM_WORLD, &request1);
                        MPI_Wait(&request1, MPI_STATUS_IGNORE);


	}
	else {
			MPI_Irecv(A, 100, MPI_INT, MPI_ANY_SOURCE, 228, MPI_COMM_WORLD, &request2);
                	MPI_Wait(&request2, MPI_STATUS_IGNORE);
	}

	MPI_Bcast(A, 100, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}
