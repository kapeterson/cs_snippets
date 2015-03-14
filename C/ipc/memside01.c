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
int key = 555;



struct ipcstruct {
	int value;
	int size;
	pthread_mutex_t memMutex;
	int last;
};

int main(){
	printf("OK\n");
	
	shimid = shmget(ftok(".", key), 1024, IPC_CREAT | 0666 );
	printf("Shim id = %lu \n", shimid);

	char *p = shmat(shimid, (void *)0, 0);
	struct ipcstruct *mystruct = (struct ipcstruct *)p;
	mystruct->value = 5;
	pthread_mutexattr_t mattr;
    pthread_mutexattr_init(&mattr);
    pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(&(mystruct->memMutex), &mattr);

	pthread_mutex_lock(&(mystruct->memMutex));
	
	while ( 1 ) {
		sleep(1);
	}
	//char *x = shmat(shimid, (void *)0, 0);
	//struct ipcstruct *mystruct2 = (struct ipcstruct *)x;
	//printf("The val is %d\n", mystruct2->value);
	//pthread_mutex_lock(&(mystruct2->memMutex));

	
	//printf("Address of the memory is %p\n", thisstruct);
	//thisstruct->value = 444;
	//thisstruct->size = 12;
	//thisstruct->last = 123;
	//
	//pthread_mutexattr_t mattr;
    //pthread_mutexattr_init(&mattr);
    //pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
	//
	//
	//pthread_mutex_init(&(thisstruct->memMutex), &mattr);
	//
	//printf("Address of mutex is %p\n", &(thisstruct->memMutex));
    //
	//pthread_mutex_lock(&(thisstruct->memMutex));
	//while ( 1 ) {
	//	printf("We wait\n");
	//}
	//
	//while ( shmpointer->cacheSending == 1) {
	//	 printf("We wait\n");
	//	//pthread_cond_wait( &(shmpointer->cvProxyGo), &(shmpointer->memMutex));
	//	//printf("WE got it\n");
	//}
	
	//pthread_mutex_unlock(&(shmpointer->memMutex));


	
	return 0;
}