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



void *clientThread(void *arg){
      struct sembuf sb;
        sb.sem_op = -1;
        sb.sem_flg = 0;
        sb.sem_num = 0;

	struct timeval ttime;

	printf("Client is up.. going to signal to serverto READ\n");

    int setres = semctl(semid, 0,SETVAL,1);

	while(1){
        
		
		gettimeofday(&ttime, NULL);


		printf("I AM WAITING FOR SIGNAL TO READ.... %lu.%lu\n", ttime.tv_sec, ttime.tv_usec);
		semop(semid, &sb, 1);
		gettimeofday(&ttime, NULL);
		printf("I JUST READ \n");
		printf("I AM SENDING.... %lu.%lu\n", ttime.tv_sec, ttime.tv_usec );
		sleep(10);
		printf("I AM DONE SENDING\n");
		semctl(semid, 0, SETVAL, 1);
		//printf("Using resource to hand over to the server\n");
		//printf("OK\n");
	}
}


int main(int argc, char **argv){

	pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

   	signal(SIGINT, signal_callback_handler);


	 key_t semkey = ftok(".", 'A');
        semid = semget(semkey, 1, 0660);
	
	if ( semid < 0 ) {
                printf("Error creating sem \n");
                exit(1);
        }
	
	int semval = semctl(semid, 0, GETVAL, 0);
	printf("The semval is now %d\n", semval);

	pthread_t thread;

	int tresult = pthread_create(&thread, NULL, clientThread, NULL);

	if ( tresult ) {
		printf("ERROR creating threaed\n");
		return 1;
	}
	
	pthread_join(thread, NULL);

	printf("OK brah\n");
	return 0;
}
