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

#ifndef _POSIX_THREAD_PROCESS_SHARED	
#error "This platform does not support process shared mutex"	
#endif
#include "ipcstruct.h"

key_t key = 123;


char *p;
int shimid;

static void _sig_handler(int signo){
  if (signo == SIGINT || signo == SIGTERM){
	printf("Deleting it yo\n");
	shmdt(p);
	shmctl(shimid, IPC_RMID, NULL);

    exit(signo);

  }
}

int main(){
	printf("OK\n");
	if (signal(SIGINT, _sig_handler) == SIG_ERR){
		fprintf(stderr,"Can't catch SIGINT...exiting.\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGTERM, _sig_handler) == SIG_ERR){
		fprintf(stderr,"Can't catch SIGTERM...exiting.\n");
		exit(EXIT_FAILURE);
	}
	shimid = shmget(ftok(".", key), sizeof(ipcstruct), IPC_CREAT | 0777 );
	
	if ( shimid < 0 ) {
		printf("error");
		perror("shmic_creat");
		exit(1);
	}
	//printf("Shim id = %lu \n", shimid);
	printf("shimid worked %d\n", shimid);
	p = shmat(shimid, (void *)NULL, 0);
	ipcstruct *mystruct = (ipcstruct *)p;
	mystruct->value = 5;
	mystruct->thekey = 444;
	
	// INITIALIZE THE MUTEX
	pthread_mutexattr_t mattr;
	int ret = pthread_mutexattr_init(&mattr);
	printf("REsult of mutex attribute init = %d\n", ret);
	
	pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);

	
	// INIT THE COND VAR
	pthread_condattr_t cond_attr;
    pthread_condattr_init(&cond_attr);
    pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);
	
	// initialize the mutex and cond var
	pthread_mutex_init(&(mystruct->memMutex), NULL);
	
	pthread_mutex_init(&(mystruct->memMutex), &mattr);	
	pthread_cond_init(&(mystruct->cvProxyGo), &cond_attr);
	pthread_cond_init(&(mystruct->cvCacheGo), &cond_attr);
	
	
	pthread_mutex_lock(&(mystruct->memMutex));
	printf("Sleeping\n");
	sleep(10);
	
	pthread_mutex_unlock(&(mystruct->memMutex));
	
//	sleep(15);
//	
//	while ( 1 ||  mystruct->value == 5 ) {
//		printf("We waitin\n");
//		pthread_cond_wait(&(mystruct->cvProxyGo), &(mystruct->memMutex));
//		printf("Checking again\n");
//		
//	}
//	
//	printf("WE came out of the wait with value = %d\n", mystruct->value);
//	sleep(5);
//	pthread_mutex_unlock(&(mystruct->memMutex));
//	
//	shmdt(p);
//	shmctl(shimid, IPC_RMID, NULL);



	
	return 0;
}
