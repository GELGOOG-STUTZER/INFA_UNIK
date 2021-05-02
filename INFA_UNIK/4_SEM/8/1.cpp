#include <stdio.h>
#include <omp.h>

int main () {
	int a[100000], b[100000], c[100000];
	for(int i = 0; i < 100000; i++) {
		a[i] = i % 6;
		b[i] = i % 4;
	}
	double time1, time2;
	omp_set_num_threads(1);
	time1 = omp_get_wtime();
	#pragma omp parallel 
	{
		for(int i = 0; i < 100000; i++) {
			c[i] = a[i] + b[i];
		}
	}
	time2 = omp_get_wtime();
	printf("TIME (THREAD = 1) %lf\n", time2-time1);
	time1 = omp_get_wtime();
	#pragma parallel for
	for (int i = 0; i < 100000; i++) {
		a[i] = i*3 + i*i/(i+1);
		b[i] = 1-i;
		c[i] = (a[i] * b[i])/(a[i]+b[i]);
	}
	time2 = omp_get_wtime();
        printf("TIME (THREAD = 1) %lf\n", time2-time1);
	return 0;
}
