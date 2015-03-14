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


int shmd;

long shimid;
key_t key = 66607;
int LEN = 1024;
struct ipcstruct *mystruct;

struct ipcstruct {
	int value;
	int size;
	int cachesending;
	int proxysending;
	pthread_mutex_t memMutex;
	pthread_cond_t  cvProxyGo;
	pthread_cond_t  cvCacheGo;	
};


static void _sig_handler(int signo){
  if (signo == SIGINT || signo == SIGTERM){
	printf("Interrupted\n");
	munmap(mystruct, LEN);
	shm_unlink("555");
    exit(signo);

  }
}



int main(){
  if (signal(SIGINT, _sig_handler) == SIG_ERR){
    fprintf(stderr,"Can't catch SIGINT...exiting.\n");
    exit(EXIT_FAILURE);
  }

  if (signal(SIGTERM, _sig_handler) == SIG_ERR){
    fprintf(stderr,"Can't catch SIGTERM...exiting.\n");
    exit(EXIT_FAILURE);
  }
	
	
	printf("OK\n");
	
	char memName[15];
	sprintf(memName, "%d", 555);

	shmd = shm_open(memName, O_CREAT | O_RDWR, 0666);
	printf("File handle is %d\n", shmd);
	
	ftruncate(shmd, sizeof(struct ipcstruct));
	
	mystruct = (struct ipcstruct *)mmap(NULL, sizeof(struct ipcstruct), 
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
	
	
	while ( 1 ) {
	pthread_mutex_lock(&(mystruct->memMutex));

		
		while( mystruct->cachesending == 1){
			printf("Waiting....\n");
			pthread_cond_wait(&(mystruct->cvProxyGo), &(mystruct->memMutex) );
		}
		printf("We got the lock doing work....\n");
		mystruct->proxysending = 1;
		sleep(5);
		mystruct->proxysending = 0;
		mystruct->cachesending = 1;
	
		pthread_mutex_unlock(&(mystruct->memMutex));
		pthread_cond_signal(&(mystruct->cvCacheGo));

	}
	return 0;
}