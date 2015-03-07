#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>


long shimid;
key_t key = 66607;


struct ipcstruct {
	int value;
	int size;

};


int main(){
	
	struct shmid_ds shmbuffer;

	shimid = shmget(key, 1024, IPC_CREAT | 0666);

	printf("Shim id = %lu \n", shimid);

	struct ipcstruct tstruct;
	tstruct.value = 5;
	tstruct.size = 666;

	char *shmpointer = shmat(shimid, NULL, 0);
	memcpy(shmpointer, &tstruct, sizeof(tstruct));	

	//strcpy(shmpointer, "ipcbrah");

	if ( shmpointer == (char * )(-1)){
		printf("there was an issue");
		return 1;
	}
	
	

	sleep(5);
	

	struct ipcstruct newstruct;
	memcpy(&newstruct, shmpointer, sizeof(struct ipcstruct));
	printf("The size read from mem is %d\n", newstruct.size);

	//char rd[50];
	//strcpy(rd,shmpointer);
	//printf("Read valud of %s from ipc\n", rd);
	shmdt(&shmpointer);
	shmctl(shimid, IPC_RMID, &shmbuffer);
	printf("OK brah\n");
	return 0;
}
