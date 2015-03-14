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
	int last;
};

int main(int argc, char **argv){

	if ( argc < 2 ) {
		printf("ERROR you need to vit eh mem id\n");
		return 0;
	}
	
	printf("Arg 1 is %s\n", argv[1]);
	
	int memid = atoi(argv[1]);
	printf("Mem id is %d\n", memid);

	char *p = shmat(shimid, (void *)0, 0);
	struct ipcstruct *mystruct = (struct ipcstruct *)p;
	pthread_mutex_lock(&mystruct->memMutex);
	printf("We did it\n");
	return 0;
}