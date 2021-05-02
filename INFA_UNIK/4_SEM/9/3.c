#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	char* buf1 = "РАЗ РАЗ РАЗ\n";
	char* buf2 = "ЭТО ХАРДБАСС \n";
	char* buf3 = (char*)malloc(50*sizeof(char));
	MPI_Request request1, request2;
//	printf("Hello world\n");
	int size, rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf("RANK = %d\nSIZE = %d\n", rank, size);
	if(rank == 0) {
	MPI_Isend(buf2, 50, MPI_CHAR, 1, 228, MPI_COMM_WORLD, &request1);
	MPI_Wait(&request1, MPI_STATUS_IGNORE);
	MPI_Irecv(buf3, 50, MPI_CHAR, MPI_ANY_SOURCE, 228, MPI_COMM_WORLD, &request2);
	MPI_Wait(&request2, MPI_STATUS_IGNORE);
	printf("%s\n", buf3);
	}
	if(rank == 1) {
	MPI_Irecv(buf3, 50, MPI_CHAR, MPI_ANY_SOURCE, 228, MPI_COMM_WORLD, &request2);
	MPI_Wait(&request2, MPI_STATUS_IGNORE);
	printf("%s\n", buf3);
	MPI_Isend(buf1, 50, MPI_CHAR, 0, 228, MPI_COMM_WORLD, &request1);
	MPI_Wait(&request1, MPI_STATUS_IGNORE);
	}
	MPI_Finalize();
	return 0;
}
