#include <stdio.h>
#include <omp.h>
#include <math.h> //надо писать в конце -lm
#include <stdlib.h>

int main () {
        double a = 0, b = 0, c = 0, d = 0;
        double time1, time2;
	double N = 1000000000;
	double pi = 0;
	time1 = omp_get_wtime();
	#pragma parallel for
	for(int i = 0; i < N; i++) {
		pi = pi + (4/N)*sqrt(1-(i/N)*(i/N));
	}
	printf("PARALLEL FOR PI = %lf\n", pi);
	time2 = omp_get_wtime();
        printf("TIME (PARALLEL FOR) %lf\n", time2-time1);
        time1 = omp_get_wtime();
	int cores;
        #pragma omp parallel 
	{
		cores = omp_get_num_threads();
	}
	double* results = NULL;
	printf("CORES = %d\n", cores);
	results = (double*)malloc(cores * sizeof(double));
	for(int i = 0; i < cores; i++) {
                results[i] = 0;
        }
	#pragma omp parallel 
	{
		int cur_core = omp_get_thread_num();
		for(int i = 0; i < N/cores; i++) {
               		results[cur_core] = results[cur_core] + (4/N)*sqrt(1-((cur_core+i*cores)/N)*((cur_core+i*cores)/N));
                }
	}
	pi = 0;
	for(int i = 0; i < cores; i++) {
                pi = pi + results[i];
        }
	printf("PI = %lf\n", pi);
        time2 = omp_get_wtime();
        printf("TIME (THREAD = AUTO) %lf\n", time2-time1);
        return 0;
}

