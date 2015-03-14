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
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

long shimid;
key_t key = 66607;


struct ipcstruct {
	int value;
	int size;
	int cachesending;
	int proxysending;
	pthread_mutex_t memMutex;
	pthread_cond_t  cvProxyGo;
	pthread_cond_t  cvCacheGo;	
};

int main(int argc, char **argv){
	printf("OK\n");
	int shmd;
	
	if ( argc < 2 ) {
		printf("you must give a file name");
		return 1;
	}
	
	char memName[15];
	strcpy(memName, argv[1]);
	//sprintf(memName, "%d", 555);
	//shmd = shm_open(memName, O_CREAT | O_RDWR, 0666);
	shmd = atoi(memName);
	
	//ftruncate(shmd, sizeof(struct ipcstruct));
	
	struct ipcstruct *mystruct = (struct ipcstruct *)mmap(NULL, sizeof(struct ipcstruct),
		PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0);
		
	printf("The value is %d\n", mystruct->value);
	printf("Tring to get the lock\n");


	while ( 1 ) {
	
	
		pthread_mutex_lock(&(mystruct->memMutex));
		
		while ( mystruct->proxysending == 1 ) {
			printf("We're waiting now\n");
			pthread_cond_wait(&(mystruct->cvCacheGo), &(mystruct->memMutex) );

		}
		
		mystruct->cachesending = 1;
		
		printf("We got it... doing work\n");
		sleep(5);
		printf("Done.. signalling\n");
		mystruct->cachesending = 0;
		mystruct->proxysending = 1;
		pthread_mutex_unlock(&(mystruct->memMutex));

		pthread_cond_signal(&(mystruct->cvProxyGo));

		

	}

	return 0;
}