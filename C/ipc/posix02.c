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

int main(){
	printf("OK\n");
	int shmd;
	shmd = shm_open("test", O_CREAT | O_RDWR, 0666);
	//ftruncate(shmd, sizeof(struct ipcstruct));
	
	struct ipcstruct *mystruct = (struct ipcstruct *)mmap(NULL, sizeof(struct ipcstruct),
		PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0);
		
	printf("The value is %d\n", mystruct->value);
	printf("Tring to get the lock\n");
	pthread_mutex_lock(&(mystruct->memMutex));
	
	
	mystruct->cachesending = 0;

	pthread_mutex_unlock(&(mystruct->memMutex));
	pthread_cond_signal(&(mystruct->cvProxyGo));
	
	printf("We got it\n");
	return 0;
}