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
	ftruncate(shmd, sizeof(struct ipcstruct));
	
	struct ipcstruct *mystruct = (struct ipcstruct *)mmap(NULL, sizeof(struct ipcstruct), 
		PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0);
		
	mystruct->value = 23;

	
	// INIT THE MUTEX
	pthread_mutexattr_t mattr;
    pthread_mutexattr_init(&mattr);
    pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(&(mystruct->memMutex), &mattr);

	// INIT THE COND
	pthread_condattr_t cond_attr;
    pthread_condattr_init(&cond_attr);
    pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&(mystruct->cvProxyGo), &cond_attr);
    pthread_cond_init(&(mystruct->cvCacheGo), &cond_attr);
	pthread_condattr_destroy(&cond_attr);
	
	mystruct->cachesending = 1;
	mystruct->proxysending = 0;
	
	pthread_mutex_lock(&(mystruct->memMutex));

	
	while( mystruct->cachesending == 1){
		printf("Wait\n");
		pthread_cond_wait(&(mystruct->cvProxyGo), &(mystruct->memMutex) );
	}
	
	
	pthread_mutex_unlock(&(mystruct->memMutex));
	
	return 0;
}