#include <stdio.h>
#include "msg.h"

int main ( int argc, char **argv){

	CLIENT *clnt;
	int *result;
	char *server;
	char *message;
 
	if (argc != 3) {
		fprintf(stderr, "usage: %s host message\n", argv[0]);
		exit(1);
	}


	server = argv[1];
	message = argv[2];
	printf("SERVER = %s  MSG = %s\n", server, message);

	clnt = clnt_create(server, MESSAGEPROG, PRINTMESSAGEVERS, "tcp");
    if (clnt == NULL) {

        clnt_pcreateerror(server);
        exit(1);
    }
    
    result = printmsg_1(message, clnt);
    if (result == NULL) {
        clnt_perror(clnt, server);
        exit(1);
    }

    if (*result == 0) {

        fprintf(stderr, "%s: %s couldn't print your message\n",
        argv[0], server);
        exit(1);
    }

	printf("Bye\n");
	return 0;
	return 0;
}