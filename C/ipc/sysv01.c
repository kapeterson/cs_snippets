#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>



long shimid;
key_t key = 66607;

int main(){
	
	struct shmid_ds shmbuffer;

	shimid = shmget(key, 1024, IPC_CREAT | 0666);

	printf("Shim id = %lu \n", shimid);

	char *shmpointer = shmat(shimid, NULL, 0);

	if ( shmpointer == (char * )(-1)){
		printf("there was an issue");
		return 1;
	}
	
	

	sleep(10);
	shmdt(&shmpointer);
	shmctl(shimid, IPC_RMID, &shmbuffer);
	printf("OK brah\n");
	return 0;
}
