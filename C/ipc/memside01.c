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
	int proxySending;
	int cacheSending;
	pthread_mutex_t memMutex;

};

int main(){
	printf("OK\n");
	
	shimid = shmget(key, 1024, IPC_CREAT | 0666);

	printf("Shim id = %lu \n", shimid);


	pthread_mutexattr_t mattr;
    pthread_mutexattr_init(&mattr);
    pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);

	
	struct ipcstruct *thisstruct = shmat(shimid, NULL, 0);
	pthread_mutex_init(&thisstruct->memMutex, &mattr);
	thisstruct->value = 444;
	
	pthread_mutex_lock(&(thisstruct->memMutex));
	while ( 1 ) {
		printf("We wait\n");
	}
	//
	//while ( shmpointer->cacheSending == 1) {
	//	 printf("We wait\n");
	//	//pthread_cond_wait( &(shmpointer->cvProxyGo), &(shmpointer->memMutex));
	//	//printf("WE got it\n");
	//}
	
	//pthread_mutex_unlock(&(shmpointer->memMutex));


	
	return 0;
}