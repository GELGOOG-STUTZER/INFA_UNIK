#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstring>

#define M 10000
#define N 50.0
#define A 0.004
#define dt 0.25

int main(int argc, char** argv) {
	std::ofstream of("results0.dat");
	if (!of.is_open()) {
		std::cout << "FILE ERROR\n";
		exit(EXIT_FAILURE);
	}
	double U0[M], U[M];
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
		for(int m = 0; m < M; m++) {
			if(m == 0 || m == M - 1) {
				U[m] = 0;
			}
			else {
				U[m] = ((A*A) * dt/(h*h)) * (U0[m+1] - 2 * U0[m] + U0[m-1]) + U0[m];
			}
		}
		memcpy(U0, U, M * sizeof(double));
	}

	for(int i = 0; i < M; i++) {
		of << i * h << "\t" << U[i] << "\n";
        }
	of.close();
	return 0;
}
