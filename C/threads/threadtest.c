#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void *my_thread(){

	int i = 0;
	while ( i < 100 ) {
		printf ("OK YO %d\n", i);
		i++;
	}
	
	return;


}


int main(int argc, char **argv){

	pthread_t test_thread;


	int result = 0;

	result = pthread_create(&test_thread, NULL, my_thread, NULL);
	result = pthread_join(test_thread, NULL);
	
	printf("OK\n\n");
	return 0;
}
