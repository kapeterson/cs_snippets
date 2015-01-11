// compile insturction gcc -fopenmp -o omptest omptest.c

#include <stdio.h>
#include <omp.h>

int main() {
	int nthreads, tid;

	printf("Hello");
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		printf("Hello from thread %d\n",tid);
		if ( tid == 0 ) {
			nthreads = omp_get_num_threads();
			printf("num threads is %d\n",nthreads);
		}

	}
}
