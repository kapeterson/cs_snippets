#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){

	//int pid;
	pid_t  pid = fork();
	
	//printf("The pid is %d\n", (int)pid);
	if ( pid < 0 ) {
		fprintf(stderr, "Fork Failed");
		return 1;
	} else if ( pid == 0  ) {
		printf("We good yall %d\n", (int)pid);

		printf("Child yo... do do dis");
		sleep(5);
		//execlp("/bin/ls", "ls", NULL);
	} else {
		
		printf("Original thread gonna wait\n");
		wait(NULL);
		printf("Chile done yo\n");

	}

	printf("OK\n");
	return 0;	
}
