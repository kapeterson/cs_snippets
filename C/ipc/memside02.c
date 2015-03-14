#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
long shimid;
key_t key = 66607;


struct ipcstruct {
	int value;
	int size;
	pthread_mutex_t memMutex;

};


int main(){
	printf("side2\n");
	
	shimid = shmget(key, 1024,  0666);
	if ( shimid < 0 ) {
		perror("no_shmid");
		exit(1);
	}
	printf("Shim id = %lu \n", shimid);


	struct ipcstruct *shmpointer = (struct ipcstruct * )shmat(shimid, NULL, 0);

	
	printf("The value of it is %d\n", shmpointer->value);
	//memcpy(shmpointer, &tstruct, sizeof(tstruct));	
	
	
	int scope;
	
	pthread_mutex_lock(&shmpointer->memMutex);
		
		//while ( shmpointer->proxySending == 1 ) {
		//	pthread_cond_wait( &(shmpointer->cvProxyGo), &(shmpointer->memMutex));
		//}
		printf("WE send\n");

	pthread_mutex_unlock(&(shmpointer->memMutex));
	printf("We signal now\n");
	//shmpointer->cacheSending = 0;
	
	//int res = pthread_cond_signal(&(shmpointer->cvProxyGo));
	//printf("Result of signal is %d\n", res);
	return 0;
}