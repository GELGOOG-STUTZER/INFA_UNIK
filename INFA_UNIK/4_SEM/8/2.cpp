#include <stdio.h>
#include <omp.h>
#include <math.h>

int main () {
        double a = 0, b = 0, c = 0, d = 0;
        double time1, time2;
	double N = 1000000000;
	double pi = 0;
	int cur_core;
	time1 = omp_get_wtime();
	#pragma parallel for
	for(int i = 0; i < N; i++) {
		pi = pi + (4/N)*sqrt(1-(i/N)*(i/N));
	}
	printf("SINGLE CORE PI = %lf\n", pi);
	time2 = omp_get_wtime();
        printf("TIME (THREAD = 1) %lf\n", time2-time1);
        omp_set_num_threads(4);
	int cores = omp_get_num_threads();
	double results[cores];
	for(int i = 0; i < cores; i++) {
		results[i] = 0;
	}
        time1 = omp_get_wtime();
        #pragma omp parallel 
        {
		int cores = omp_get_num_threads();
		for(int j = 0; j < cores; j++) {
			cur_core = omp_get_thread_num();
			if(cur_core == j) {
				for(int i = 0; i < N/j; i++) {
                        		results[j] = results[j] + (4/N)*sqrt(1-((j+i*j)/N)*((j+i*j)/N));
                		}
			}
		}
	}
	pi = 0;
	for(int i = 0; i < cores; i++) {
                pi = pi + results[i];
        }
	printf("PI = %lf\n", pi);
        time2 = omp_get_wtime();
        printf("TIME (THREAD = 4) %lf\n", time2-time1);
        return 0;
}

