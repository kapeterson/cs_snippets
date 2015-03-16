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

#include "ipcstruct.h"

key_t key = 123;




int main(int argc, char **argv){

	int shmid  = shmget(ftok(".", key), sizeof(ipcstruct),  0777 );	
	printf("Mem id is ->%lu<-\n", shmid);
	char *p = shmat(shmid, (void *)NULL, 0);
	
	
	ipcstruct *mystruct = (ipcstruct *)p;
	

	
	
	printf("Tring to lock\n");
	pthread_mutex_lock(&(mystruct->memMutex));
	printf("We got it\n");
	
//		printf("My value is %d\n", mystruct->value);
//		printf("my value is %d\n", mystruct->thekey);
//		
//		while ( mystruct->value == 0 ) {
//			pthread_cond_wait(&(mystruct->cvCacheGo), &(mystruct->memMutex));
//
//		}
//	mystruct->value = 0;
//	
//	printf("Sent the signal\n");
//	pthread_cond_signal(&(mystruct->cvProxyGo));
//
//	pthread_mutex_unlock(&(mystruct->memMutex));
//
	sleep(5);
	
	return 0;
}
