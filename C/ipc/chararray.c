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

typedef struct {
	int val;
	int size;
	
} ipcstruct;
int main () {

	key_t key = 432;
	int shimid = shmget(ftok(".", key), 1024, IPC_CREAT  | 0777 );
	
	if ( shimid < 0 ) {
		printf("error");
		perror("shmic_creat");
		exit(1);
	}
	
	printf("shimid worked %d\n", shimid);
	
	ipcstruct *p = shmat(shimid, (void *)NULL, 0);
	printf("Size of ipcstruct is %d\n", (int)sizeof(ipcstruct));
	
	char *str = (void *)p + sizeof(ipcstruct);
	str[0] = 'c';
	str[1] = 'h';
	
	
	ipcstruct *p2 = shmat(shimid, (void *)NULL, 0);
	char *str2 = (void *)p + sizeof(ipcstruct);
	printf("Char 1 = %c 2= %c\n", str2[0], str2[1]);
	
	//char str[50];
	//memcpy(p, str, sizeof(str));
	//p[0] = 'c';
	//p[1] = 'h';
	//
	//char *z = shmat(shimid, (void *)NULL, 0);
	//printf("The first char is %c\n", z[0]);
	
	return 0;
	
}