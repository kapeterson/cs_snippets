#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


pthread_mutex_t myLock = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cvar = PTHREAD_COND_INITIALIZER;
int pred = -1;

int  gvar;


void *ThreadOne();
void *ThreadTwo();

int main(int argc, char **argv){

	pthread_t mainthread;
	pthread_t readthread;
	
	int gvar = 5;

	printf("OK brah!\n");
	pthread_create(&mainthread, NULL, ThreadOne, NULL);
	pthread_create(&readthread, NULL, ThreadTwo, NULL);	

	pthread_join(mainthread, NULL);
	pthread_join(readthread,NULL);

	return 0;


}

void *ThreadOne(){
	sleep(5);
	pthread_mutex_lock(&myLock);
		
		pred = 0;
		
	pthread_mutex_unlock(&myLock);
	pthread_cond_signal(&cvar);

}


void *ThreadTwo(){
	pthread_mutex_lock(&myLock);
	
	while ( pred == -1 ) {
		printf("WE gonna wait fer da condition\n");
		pthread_cond_wait(&cvar, &myLock);
	}	

	printf("We good now ya'll\r\n");
	
}
