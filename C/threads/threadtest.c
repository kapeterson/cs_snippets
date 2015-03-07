#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


void *my_thread(){

	int i = 0;
	while ( i < 100 ) {
		printf ("OK YO %d from thread %u\n", i, (int)pthread_self());
		sleep(1);
		i++;
	}
	
	return 0;


}


int main(int argc, char **argv){

	pthread_t test_thread[10];



	int result = 0;
	
	for ( int i = 0; i < 10; i ++) {
		printf("Creating thread  %d\n", i);
		pthread_create(&test_thread[i], NULL, my_thread, NULL);
		
	}

	for ( int i = 0; i < 10; i++ ) {
                pthread_join(test_thread[i], NULL);

	}
	printf("OK\n\n");
	return 0;
}
