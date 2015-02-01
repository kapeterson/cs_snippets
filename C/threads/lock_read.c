#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


pthread_mutex_t myLock = PTHREAD_MUTEX_INITIALIZER;
int  gvar;


void *MainThread();
void *ReadThread();

int main(int argc, char **argv){

	pthread_t mainthread;
	pthread_t readthread;
	
	int gvar = 5;

	printf("OK brah!\n");
	pthread_create(&mainthread, NULL, MainThread, NULL);
	pthread_create(&readthread, NULL, ReadThread, NULL);	

	pthread_join(mainthread, NULL);
	return 0;


}

void *MainThread(){


	while ( 1 ) {
	
		sleep(2);
		printf("We good\n");
	}
}


void *ReadThread(){
	
	while ( 1) {
		sleep(1);
		printf("we read\n");
	}
}
