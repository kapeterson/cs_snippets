#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/time.h>


int semid;

void signal_callback_handler(int signum){

	printf("Signal is %d\n", signum);
	exit(1);
}



void *serverThread(void *arg){

	// init the sem op to wait for 0
	
	struct sembuf sb;
	sb.sem_op = -1;
	sb.sem_flg = 0;
	sb.sem_num = 0;

	struct timeval ttime;

	gettimeofday(&ttime, NULL);
	printf("Waiting to hear from teh client by waiting for 1 %lu.%lu\n", ttime.tv_sec, ttime.tv_usec);
    semop(semid, &sb, 1);
	printf("We just heard from teh client");

    int semval = semctl(semid, 0, GETVAL, 0);
	printf("The value of the sem is %d\n", semval); 
      // gettimeofday(&ttime, NULL);
       // printf("Sem acquired.... Going to use our resource up%lu.%lu\n", ttime.tv_sec, ttime.tv_usec);



	while(1){
        
		gettimeofday(&ttime, NULL);
	
		printf("I AM WAITING ON SIGNAL FROM CLINET TO TELL ME TO READt %lu.%lu\n", ttime.tv_sec, ttime.tv_usec);
		semctl(semid, 0, SETVAL, 1);
		semop(semid, &sb, 1);
		int semval = semctl(semid, 0, GETVAL, 0);
		gettimeofday(&ttime, NULL);		
		printf("I JUST READ\n");
		printf("I AM SENDING.....%lu.%lu\n", ttime.tv_sec, ttime.tv_usec);
		//printf("The value of the sem was %d\n", semval);

		sleep(10);

		printf("I AM DONE SENDING\n");
		gettimeofday(&ttime, NULL);
		//printf("Releasing the resource by setval on sem %lu.%lu\n", ttime.tv_sec, ttime.tv_usec);
		
	}
}


int main(int argc, char **argv){

	pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

   	signal(SIGINT, signal_callback_handler);

	pthread_t thread;

	int tresult = pthread_create(&thread, NULL, serverThread, NULL);

	// create semaphore
	key_t semkey = ftok(".", 'A');
	semid = semget(semkey, 1, IPC_CREAT|0660);
	
	printf("result of sem get is %d\n", semid);
	if ( semid < 0 ) {
		printf("Error creating sem \n");
		exit(1);
	}

	int setres = semctl(semid, 0,SETVAL,0);


	if ( tresult ) {
		printf("ERROR creating threaed\n");
		return 1;
	}
	
	pthread_join(thread, NULL);

	printf("OK brah\n");
	return 0;
}
